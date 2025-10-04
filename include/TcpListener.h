#pragma once

#include <WS2tcpip.h>
#include <string>
#include <string_view>
#pragma comment (lib, "ws2_32.lib")

class TcpListener
{

public:

	TcpListener(const std::string& ipAddress, int port) :
		m_ipAddress(ipAddress), m_port(port) { }

	// Initialize the listener
	int init();

	// Run the listener
	int run();

protected:

	// Handler for client connections
	virtual void onClientConnected(int clientSocket);

	// Handler for client disconnections
	virtual void onClientDisconnected(int clientSocket);

	// Handler for when a message is received from the client
	virtual void onMessageReceived(int clientSocket, std::string_view msg, int length);

	// Send a message to a client
	void sendToClient(int clientSocket, std::string_view msg, int length);

	// Broadcast a message from a client
	void broadcastToClients(int sendingClient, std::string_view msg, int length);

private:

	std::string m_ipAddress;	// IP Address server will run on
	int				m_port;			// Port # for the web service
	int				m_socket;		// Internal FD for the listening socket
	fd_set			m_master;		// Master file descriptor set
};
