#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
   
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(9898);
  
  bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
 
  listen(sockfd ,10);
 
  int client_socket;
  client_socket = accept(sockfd, NULL, NULL);
  
  
  char msg[256];
  char msg2[256];
  while(1){

    printf("type to send:");
    //scanf("%s",msg);
    fgets(msg,256,stdin);
  send( client_socket, &msg, sizeof(msg),0);
 // if(strcmp(msg,"bye")==0)
    //break;
  
  recv(client_socket,&msg2,sizeof(msg2),0);

  printf("\nclient said:%s\n",msg2);  

      }

  close(sockfd);
  close(client_socket);
  return(0);
}
