#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello msg from server side";
      
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address));
    listen(server_fd, 3);

    new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen);

    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );

    //sending message on client's request 
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent successfully\n");
    return 0;
}

