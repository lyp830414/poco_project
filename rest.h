#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
 
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
using namespace Poco::Net;
using namespace Poco::Util;
 
class MyRequestHandler : public HTTPRequestHandler
{
public:
	virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp);
};
 
class MyRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
	virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest &);
};
 
class MyServerApp :public ServerApplication
{
protected:
	int main(const vector<string> &);
};
 
/*int main(int argc, char **argv)
{
	MyServerApp app;
 
	return app.run(argc, argv);
}*/
