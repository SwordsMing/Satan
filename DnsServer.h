/*
	DNS SERVER implement

 */

#include <boost/noncopyable.hpp>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpServer.h>
#include <muduo/base/Thread.h>
#include <lucifer/UdpServer.h>
#include <string>

using namespace muduo::net;
class DnsServer:boost::noncopyable
{
	public:
		DnsServer(muduo::net::EventLoop * loop,
						const InetAddress & addr,
						int nThreadNums=4,
	   					const std::string name="DNS_Server");
        ~DnsServer();
		void start();
	private:
		muduo::net::EventLoop * loop_;
		muduo::net::TcpServer Tcpserver_;
		UdpServer Udpserver_;
		std::string name_;
		Thread udpServerThread_;  //this thread uses for tcp server
		int threadNums_;   //TCP I/O thread
		void startUdpServer();

		void onTcpMessage(const muduo::net::TcpConnectionPtr & conn,
						muduo::net::Buffer* buf,
						muduo::Timestamp time);

		void onUdpMessage(const Session &session);
};
