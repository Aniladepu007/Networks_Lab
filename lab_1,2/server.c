#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
struct sockaddr *serv_addr;
struct sockaddr *cli_addr;
//serv_addr.sa_family = AF_INET;
int portno = 8080;
   //serv_addr.sin_family = AF_INET;
   //serv_addr.sin_addr.s_addr = INADDR_ANY;
   //serv_addr.sin_port = htons(portno);
int sockfd;
int addrlen= sizeof(struct sockaddr);
sockfd = socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1) {
	printf("Socket creation failed !\n");
	return 0;
}
//printf("test!");
bind(sockfd, serv_addr, addrlen);

listen(sockfd,10);

//connect (sockfd, serv_addr, addrlen);

accept(sockfd, cli_addr, (socklen_t *)sizeof(struct sockaddr));

char *msg;
msg="hello from server too!";
send(sockfd, msg, sizeof(msg),0);

//printf("test!");
	return 0;
}