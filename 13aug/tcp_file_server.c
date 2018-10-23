#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main() {
   
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

  FILE *fp =fopen("serverfile.txt","r");
  if(fp==NULL){
    printf("cannot open file\n");
    exit(0);
    }

    fgets(msg,256,fp);
    fclose(fp);

    printf("file taken:%s",msg);

  
  send( client_socket, &msg, sizeof(msg),0);
  
  close(sockfd);
  close(client_socket);
  return(0);
}
