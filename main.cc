/*

 main.cc
 
*/
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include "DnsServer.h"

int main()
{
	LOG_INFO<< "pid = "<<getpid();
	muduo::net::EventLoop loop;
	muduo::net::InetAddress listenAddr(53);

	DnsServer server(&loop,listenAddr);
	server.start();
	loop.loop();

	return 0;
}
