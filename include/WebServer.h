#pragma once
#include "TcpListener.h"

struct ServerConfig 
{
	std::string host = "127.0.0.1";
	int         port = 8080;
	// std::string root = "wwwroot";
	// std::string index = "index.html";
};

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

	static std::pair<std::string, int> loadConfigFile(void);
	// Handler for client connections
	virtual void onClientConnected(int clientSocket);

	// Handler for client disconnections
	virtual void onClientDisconnected(int clientSocket);

	// Handler for when a message is received from the client
	virtual void onMessageReceived(int clientSocket, std::string_view msg, int length);
};