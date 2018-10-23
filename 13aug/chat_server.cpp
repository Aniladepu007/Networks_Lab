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

bind(sock_des, (struct sockaddr *) &server_addr, sizeof(server_addr)  );

listen(sock_des,5);

int client_sock;

client_sock = accept(sock_des,NULL,NULL);

char text[1024];
char clientmsg[1024];

while(1) {
	bzero(text,1024);
	bzero(clientmsg,1024);
//text[1024]={0};

printf("\n\nClient_msg :\n");

recv(sock_des, &clientmsg,sizeof(clientmsg),0);

//cout<<clientmsg;
//printf("%s",clientmsg);
fputs(clientmsg,stdout);

printf("\n\nEnter your msg :\n");
fgets(text,1024,stdin);
send(client_sock, &text,sizeof(text),0);

}

close(sock_des);
	return 0;
}
