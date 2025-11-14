#pragma once
#include "TcpListener.h"

struct ServerConfig
{
	std::string host = "127.0.0.1";
	int         port = 8080;
	// std::string root = "wwwroot";
	// std::string index = "index.html";
};

/**
 * @brief This is main class WebServer which has all basics
 * functionality
 *
 *
*/

class WebServer : public TcpListener
{
public:
	WebServer()
		: WebServer(loadConfigFile())
	{
	}
	WebServer(const std::pair<std::string, int>& cfg)
		: TcpListener(cfg.first, cfg.second) {
	}
	WebServer(const std::string& ipAddress, int port)
		: TcpListener(ipAddress, port) {
	}
protected:
	/**
	 * @brief Loads and parses the details created by user.
	 * (see folder 'resources' for details)
	 * @return std::pair<std::string, int>
	 * Return a pair of <host_name, port_value>
	 * - std::string : host name	(e.g. 127.0.0.1)
	 * - int  		 : port number	(e.g. 8080)
	 */
	static std::pair<std::string, int> loadConfigFile(void);
	/**
	 * @brief Handler for client connections
	 * @param clientSocket The socket descriptor of the connected client
	 */
	virtual void onClientConnected(int clientSocket);
	/**
	 * @brief Handler for client disconnections
	 *
	 * @param clientSocket The socket descriptor of the client that disconnected
	 */
	virtual void onClientDisconnected(int clientSocket);
	/**
	 * @brief  Handler for when a message is received from the client.
	 * @param clientSocket - The socket descriptor of the client.
	 * @param msg A view of the received message. The server uses recv()  
	 * to read raw bytes into a char buffer, and std::string_view 
	 * provides a lightweight, non-owning view of that buffer.
	 * @param length The number of bytes received from recv(), representing 
	 * the actual message length.
	 */
	virtual void onMessageReceived(int clientSocket, std::string_view msg, int length);
};