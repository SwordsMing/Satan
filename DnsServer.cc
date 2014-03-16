#include "DnsServer.h"
#include <boost/bind.hpp>


DnsServer::DnsServer(muduo::net::EventLoop* loop,
					const muduo::net::InetAddress & addr,
					int nThreadNums,
					const std::string name)
	:loop_(loop),
	threadNums_(nThreadNums),
	Tcpserver_(loop,addr,"Dns_Tcp"),
	Udpserver_(addr.getSockAddrInet()),
	udpServerThread_(boost::bind(&DnsServer::startUdpServer,this))
{

	Tcpserver_.setMessageCallback(boost::bind(&DnsServer::onTcpMessage,this,_1,_2,_3));
	Tcpserver_.setThreadNum(threadNums_);
	Udpserver_.setMessageCallback(boost::bind(&DnsServer::onUdpMessage,this,_1));
}
DnsServer::~DnsServer(){

}

void DnsServer::start(){

	Tcpserver_.start();	
	udpServerThread_.start();
//	Udpserver_.startServer();
}
void DnsServer::startUdpServer(){

	Udpserver_.startServer();
}
void DnsServer::onTcpMessage(const muduo::net::TcpConnectionPtr & conn,
				muduo::net::Buffer * buf,
				muduo::Timestamp time){


	//for test-echo
	muduo::string msg(buf->retrieveAllAsString());
	conn->send(msg);	
}

void DnsServer::onUdpMessage(const Session & session){



}
