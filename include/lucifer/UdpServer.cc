#include "UdpServer.h"
#include <assert.h>

UdpServer::UdpServer(std::string ip,std::string port){

		start_ = false;
		bzero(&serverAddr_,sizeof(serverAddr_));
		serverAddr_.sin_family = AF_INET;
		serverAddr_.sin_port = htons(atoi(port.c_str()));
		serverAddr_.sin_addr.s_addr = inet_addr(ip.c_str());
}
UdpServer::UdpServer(const struct sockaddr_in & addr){
		
		start_ = false;
		serverAddr_ = addr;
}

UdpServer::~UdpServer(){

}

void UdpServer::startServer(){

		assert(!start_);
		start_ = true;
		socket_ = ::socket(AF_INET,SOCK_DGRAM,0);
		if(socket< 0){
				//err
		}
		if(bind(socket_,(sockaddr*)&serverAddr_,sizeof(serverAddr_))< 0){
				//err
		}
		session_.setSocket(socket_);
		while (start_){

			session_.read();
			messageCb_(session_);	
		}

}

void UdpServer::stopServer(){

		assert(start_);
		start_ = false;
}

