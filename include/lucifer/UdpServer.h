/*
A simple implement of UDP-SERVER
MODE:iteration
2014/03/13
*/

#include "Session.h"
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <muduo/base/Logging.h>
#include <muduo/base/Timestamp.h>
#include <string>

using namespace muduo;

class UdpServer: boost::noncopyable
{
	public:
		typedef boost::function<void(const Session & session)> messageCallBack;
	public:
		UdpServer(std::string ip,std::string port);
		UdpServer(const struct sockaddr_in & addr);
		~UdpServer();
		void startServer();
		void stopServer();
		void setMessageCallback(const messageCallBack & cb){
				messageCb_ = cb;
	     }

	private:
		bool start_;
		messageCallBack messageCb_;
		int socket_;
		struct sockaddr_in serverAddr_;
		Session session_;
};

