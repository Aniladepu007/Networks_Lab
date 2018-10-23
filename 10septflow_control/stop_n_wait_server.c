//Program for the Server side of Client-Server Chat Application using TCP
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int opt = 1;
    char sen_msg[1024];
    char rcv_msg[1024];
    char *hello = "Hello from server";

    // Creating server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //Enabling reuse of address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))<0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    //Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    //Listening to client
    if (listen(server_fd, 5) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //Accepting connection request
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Connection Established.\n");
    }

    //Sending and receiving messages
    while(1){

        recv( new_socket , rcv_msg, 1024 , 0);
        //closing client and server socket
        if(strncmp(rcv_msg,"end",3)==0)
        {
            printf("Closing server\n");
            strcpy(sen_msg,"end");
            send(new_socket , sen_msg , 1024 , 0 );
            shutdown(new_socket,2);
            shutdown(server_fd,2);
            exit(EXIT_SUCCESS);
        }

        printf("\nPackets Recieved \t\t: %s\n",rcv_msg );
        char ch[100];


            printf("\nEnter 'y' for ACK and 'n'for  NACK for the packet %c : ",rcv_msg[0]);
            scanf("%[^\n]%*c",ch );
            strncpy(sen_msg,ch,1);


        sen_msg[strlen(rcv_msg)]='\0';



        //Closing Client and Server Socket
        if(strncmp(sen_msg,"end",3)==0)
        {
            printf("Closing server\n");
            strcpy(sen_msg,"end");
            send(new_socket , sen_msg , 1024 , 0 );
            shutdown(new_socket,2);
            shutdown(server_fd,2);
            exit(EXIT_SUCCESS);
        }

        send(new_socket , sen_msg , 1024 , 0 );
    }
    return 0;
}
