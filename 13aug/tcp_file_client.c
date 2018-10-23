#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

int main()
{
   
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(9898);
  
  int connection = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
 
  char server_msg[256];
  recv(sockfd, &server_msg, sizeof(server_msg), 0);
  

FILE *fp2=fopen("clientfile.txt","w");

fputs(server_msg,fp2);
fclose(fp2);

 close(sockfd);

 return(0);	
}  
