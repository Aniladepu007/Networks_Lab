#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <strings.h>
int main() {
int sock_des;
sock_des = socket(AF_INET,SOCK_STREAM,0);

struct sockaddr_in server_addr;
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(5060);
server_addr.sin_addr.s_addr = INADDR_ANY;

int connection_status = connect(sock_des, (struct sockaddr *) &server_addr, sizeof(server_addr));
if(connection_status == -1)
	printf("error in connecting to the server!\n");
char text[1024];
char server_msg[1024];

while(1) {

bzero(text,1024);
bzero(server_msg,1024);

printf("\n\nEnter your msg :\n");
fgets(text,1024,stdin);
//cin>>text;
//cout<<text;
send(sock_des, &text, sizeof(text),0);
//
printf("\n\nMsgfrom server :\n");
recv(sock_des, &server_msg,sizeof(server_msg),0);
fputs(server_msg,stdout);
//printf("%s",server_msg);

//fputs(server_msg);
}

close(sock_des);

	return 0;
}
