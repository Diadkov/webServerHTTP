#include "WebServer.h"

int main()
{
	WebServer webServer;
	if (webServer.init() != 0)
		return -1;

	return webServer.run();
}
