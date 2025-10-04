#include <string>
#include <istream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <vector>
#include <iterator>
#include <map>
#include <ctime>
#include <algorithm>
#include <cctype>


#include "WebServer.h"

std::string getCurrentDate() {
    std::time_t t = std::time(nullptr);
    std::tm* gmt = std::gmtime(&t);
    char buf[30];
    std::strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S GMT", gmt);
    return std::string(buf);
}

// Handler for when a message is received from the client
void WebServer::onMessageReceived(int clientSocket, std::string_view msg, int length)
{
    std::string request(msg.data(), length);

    // Find end of request line (CRLF) and end of headers block (CRLFCRLF)
    size_t lineEnd = request.find("\r\n");
    size_t hdrsStart = lineEnd + 2;
    size_t hdrsEnd = request.find("\r\n\r\n", hdrsStart);

    // Extract request line and headers block
    std::string requestLine = request.substr(0, lineEnd);
    std::string headersBlock = request.substr(hdrsStart, hdrsEnd - hdrsStart);

    // Parse request line into method, target, and version
    std::istringstream rl(requestLine);
    std::string method, target, version;
    rl >> method >> target >> version;

    // Parse each header line into a map<lowercase-name, value>
    std::map<std::string, std::string> headers;
    std::istringstream hs(headersBlock);
    std::string line;

    while (std::getline(hs, line))
    {
        // Split on first colon
        size_t colon = line.find(':');
        if (colon == std::string::npos) continue;

        // Extract name and value, then trim whitespace
        std::string name = line.substr(0, colon);
        std::string value = line.substr(colon + 1);

        auto ltrim = [](std::string& s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                [](unsigned char c) { return !std::isspace(c); }));
            };
        auto rtrim = [](std::string& s) {
            s.erase(std::find_if(s.rbegin(), s.rend(),
                [](unsigned char c) { return !std::isspace(c); }).base(), s.end());
            };
        ltrim(name);  rtrim(name);
        ltrim(value); rtrim(value);

        // Convert header name to lowercase for case-insensitive lookup
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);

        headers[name] = value;
    }

    // Default response values (404 Not Found)
    std::string content = "<h1>404 Not Found</h1>";
    std::string htmlFile = "/index.html";
    int         statusCode = 404;

    // If this is a valid GET request, extract the requested path
    if (method == "GET" && !target.empty())
    {
        htmlFile = (target == "/") ? "/index.html" : target;
    }
    else // other methods
    {
        std::string resp =
            "HTTP/1.1 405 Method Not Allowed\r\n"
            "Allow: GET\r\n"
            "Content-Length: 0\r\n"
            "\r\n";
        sendToClient(clientSocket, resp.data(), static_cast<int>(resp.size()));
        return;
    }

    // Open the requested file from wwwroot
    std::ifstream file("wwwroot" + htmlFile);
    if (file.good())
    {
        // Read entire file into content string
        content.assign(std::istreambuf_iterator<char>(file),
            std::istreambuf_iterator<char>());
        statusCode = 200;
    }
    file.close();

    // Build HTTP response
    std::ostringstream oss;
    static const std::map<int, std::string> reasonPhrases = {
        {200, "OK"},
        {404, "Not Found"}
    };

    // Status line
    oss << "HTTP/1.1 " << statusCode << " " << reasonPhrases.at(statusCode) << "\r\n";

    // Standard headers
    oss << "Date: " << getCurrentDate() << "\r\n";
    oss << "Server: MyWebserv/1.0\r\n";
    oss << "Content-Type: text/html\r\n";
    oss << "Content-Length: " << content.size() << "\r\n";
    oss << "Connection: close\r\n";
    oss << "\r\n";

    // Body
    oss << content;

    // Send response (exact number of bytes, no extra null terminator)
    std::string response = oss.str();
    sendToClient(clientSocket, response.c_str(), static_cast<int>(response.size()));
}

// Handler for client connections
void WebServer::onClientConnected(int clientSocket)
{

}

// Handler for client disconnections
void WebServer::onClientDisconnected(int clientSocket)
{
	
}