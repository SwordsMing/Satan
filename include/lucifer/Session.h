/*

 A session stands for a udp server-client's interactive

*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//#include <boost/noncopyable.hpp>
#include <muduo/base/Timestamp.h>
#include <string.h>

using namespace muduo;
class Session
{
	private:
		struct sockaddr_in peerAddr_;
		int socket_;
		char buffer_[1500]; //MTU
		Timestamp timeStamp_;
	public:
		Session(int socket,const struct sockaddr_in & addr):
			peerAddr_(addr),
			socket_(socket)
		{}
		Session(){}
		void setSocket(int socket){socket_ = socket;}
		void read(){
			
			memset(buffer_,0,sizeof(buffer_));
			socklen_t len = sizeof(peerAddr_);
			::recvfrom(socket_,buffer_,sizeof(buffer_),MSG_DONTWAIT,(struct sockaddr*)&peerAddr_,&len);
			timeStamp_ = Timestamp::now();
		}
		int write(const void * msg,int len){

			socklen_t len_ = sizeof(peerAddr_);
			return ::sendto(socket_,msg,len,0,(struct sockaddr*)&peerAddr_,len_);
		}
	    Timestamp getTimestamp()const{return timeStamp_;}

		const char * getBuffer()const{return buffer_;}
};
