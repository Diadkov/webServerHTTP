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
Implemented a basic TCP listener (`TcpListener`) using Windows Sockets (WinSock2).
Added `WebServer` class to handle HTTP requests and serve files from **wwwroot/**.
Implemented multi-client chat logic (`MultiClientChat`) for practicing concurrent connections.
Created initial project structure:
  `include/` – header files  
  `src/` – C++ source code  
  `wwwroot/` – static HTML test files  
Added **CMake** build system for cross-platform configuration.
Pushed first working version to GitHub (branch `master`).

## ✅ What has to be done
### Supported/Planned Headers
  - [ ] **Host** – virtual host routing and absolute-URI validation  
  - [ ] **User-Agent** – logging/diagnostics  
  - [ ] **Content-Length** – body size for POST/PUT and response payloads  
  - [ ] **Content-Type** – MIME type detection for requests/responses  
  - [ ] **Accept-Charset** – charset negotiation (default: UTF-8)  
  - [ ] **Authorization** – Basic auth (challenge + credential check)  
  - [ ] **Date** – RFC 7231 date in responses (GMT)  
  - [ ] **Server** – server identifier (e.g., `webServerHTTP/0.1`)  
  - [ ] **Location** – redirects (301/302/307/308)  
  - [ ] **Retry-After** – back-off hints for 429/503  
  - [ ] **WWW-Authenticate** – auth challenge for 401

### Default Error Pages
Built-in HTML pages are returned if custom ones are not provided:
  - [ ] **404 Not Found** – resource does not exist  
  - [ ] **403 Forbidden** – access denied  
  - [ ] **500 Internal Server Error** – unexpected server error
