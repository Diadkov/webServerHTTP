#pragma once
#include "TcpListener.h"

class WebServer : public TcpListener
{
public:

	WebServer(const std::string& ipAddress, int port) :
		TcpListener(ipAddress, port) { }

protected:

	// Handler for client connections
	virtual void onClientConnected(int clientSocket);

	// Handler for client disconnections
	virtual void onClientDisconnected(int clientSocket);

	// Handler for when a message is received from the client
	virtual void onMessageReceived(int clientSocket, std::string_view msg, int length);
};