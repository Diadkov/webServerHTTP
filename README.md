## 📌 About the project
**webServerHTTP** is a simple educational HTTP server written in **C++** using **Windows API (WinSock2)**.  
The main goal of this project is to practice **network programming**, understand the basics of the **HTTP protocol**,  
and learn how to build and structure a server application in C++.

It is not a production-ready server, but rather a **training project** for:
  Understanding socket programming in Windows
  Handling multiple client connections
  Serving static web content (HTML files)
  Building projects with CMake

## ✅ What has been done
TCP listener (TcpListener) + non-blocking sockets
Basic WebServer with request parsing
Serving files from wwwroot/
GET / POST / DELETE
Content-Length body reading
CMake project structure

## To Do (Roadmap)
## 1️⃣ CONFIGURATION SYSTEM (MANDATORY)

### Server-level directives
Algorithm: 1 class (ServerConfig) + the parser class (ConfigParser)
- [ ] **listen** – define host:port the server listens on
- [ ] **server_name** – domain names for virtual host routing
- [ ] **root** – base directory for serving static files
- [ ] **index** – default file served for directories
- [ ] **error_page** – map HTTP status codes to custom HTML pages  
- [ ] **client_max_body_size** – limit the size of request bodies

### Location / route directives
- [ ] **allowed_methods** – allowed HTTP methods (GET, POST, DELETE)  
- [ ] **autoindex** – enable/disable directory listing  
- [ ] **upload_store** – directory where uploaded files are saved  
- [ ] **root (per location)** – override root for this specific route  
- [ ] **index (per location)** – override index for this route  

### CGI directives
- [ ] **cgi_extension** – file extensions triggering CGI execution  
- [ ] **cgi_path** – path to the CGI interpreter (php-cgi, python3, etc.)  

### Config parser behavior
- [ ] **Multiple server blocks**  
- [ ] **Default server** behavior  
- [ ] **Support nested blocks**  
- [ ] **Support multiple location blocks**  
- [ ] **Ignore whitespace and newlines**  
- [ ] **Detect invalid syntax**  


## 2️⃣ HTTP HEADERS (MANDATORY FROM RFC 7230–7235)
- [ ] **Host**
- [ ] **User-Agent**
- [ ] **Content-Length**
- [ ] **Content-Type**
- [ ] **Accept-Charset**
- [ ] **Authorization**
- [ ] **Date**
- [ ] **Server**
- [ ] **Location**
- [ ] **Retry-After**
- [ ] **WWW-Authenticate**
- [ ] **Accept-Language**
- [ ] **Allow**
- [ ] **Content-Language**
- [ ] **Content-Location**
- [ ] **Last-Modified**
- [ ] **Referer**
- [ ] **Transfer-Encoding**


## 3️⃣ DEFAULT ERROR PAGES (REQUIRED)
- [ ] **404 Not Found**
- [ ] **403 Forbidden**
- [ ] **500 Internal Server Error**


## 4️⃣ NON-BLOCKING SERVER CORE
- [ ] **Non-blocking sockets using fcntl(O_NONBLOCK)**  
- [ ] **Single select() loop for ALL FDs**  
- [ ] **No read/write without select**  
- [ ] **Handle partial reads**  
- [ ] **Handle partial writes**  
- [ ] **State-machine per client** (READ → PROCESS → WRITE)  
- [ ] **Graceful client disconnect**  


## 5️⃣ HTTP REQUEST PARSER
- [ ] **Parse request line (METHOD URI VERSION)**  
- [ ] **Parse headers (strict RFC)**  
- [ ] **Validate Host**  
- [ ] **Normalize URL (remove ../, duplicate slashes)**  
- [ ] **Detect body type**  
- [ ] **Handle Content-Length body**  
- [ ] **Handle chunked transfer encoding**  
- [ ] **Support incomplete request reads**  


## 6️⃣ HTTP RESPONSE GENERATION
- [ ] **Create status line (HTTP/1.1 <code> <reason>)**  
- [ ] **Send required headers**  
- [ ] **Serve static files (non-blocking)**  
- [ ] **Directory handling**
      - [ ] index file  
      - [ ] autoindex (HTML generation)  
- [ ] **Correct error response fallback**  
- [ ] **Chunked responses** (when body size unknown)  
- [ ] **Keep-alive connections** (optional but recommended)  


## 7️⃣ ROUTING SYSTEM
- [ ] **Select correct server block based on Host header**  
- [ ] **Select correct location based on URI**  
- [ ] **Apply location-level root/index/allow rules**  
- [ ] **Return 405 for disallowed methods**  
- [ ] **Return 404 for missing files**  
- [ ] **Return 403 for forbidden paths**  


## 8️⃣ CGI SYSTEM (FULLY MANDATORY)
- [ ] **Fork ONLY for CGI**  
- [ ] **Set all CGI meta-variables**, including:
      - [ ] REQUEST_METHOD  
      - [ ] SCRIPT_NAME  
      - [ ] PATH_INFO  
      - [ ] PATH_TRANSLATED  
      - [ ] QUERY_STRING  
      - [ ] CONTENT_LENGTH  
      - [ ] CONTENT_TYPE  
      - [ ] SERVER_PROTOCOL  
      - [ ] SERVER_NAME  
      - [ ] SERVER_PORT  
      - [ ] GATEWAY_INTERFACE  
      - [ ] REMOTE_ADDR  
- [ ] **Send request body to CGI stdin**  
- [ ] **Read CGI stdout until EOF**  
- [ ] **Respect CGI headers (Status, Content-Type, etc.)**  
- [ ] **Support php-cgi**  
- [ ] **Correct working directory (chdir to file’s directory)**  


## 9️⃣ STABILITY / PERFORMANCE REQUIREMENTS
- [ ] **No memory leaks (valgrind clean)**  
- [ ] **No crashes even under stress**  
- [ ] **No hanging requests**  
- [ ] **FD cleanup for every client**  
- [ ] **Survive multiple parallel clients**  

