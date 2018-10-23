#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char sen_msg[1024];
    char rcv_msg[1024];
    char fr[100];
    int n;
    int wn;
    int beg=0;

    // Creating client socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        return -1;
    }

    //Providing server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    //Connecting the client socket to server socket
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("\nConnection Failed \n");
        return -1;
    }
    else
    {
        printf("Connection Established.\n");
        printf("\nEnter no. of frames -: ");
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
        {
            fr[i] = (char)(48+i);
        }
        fr[n]='\0';
        wn=1;
    }

    //Sending and Receiving Messages
    while(1)
    {

        if (beg==n)
        {
            strcpy(sen_msg,"end");
            send(sock , sen_msg , 1024 , 0 );
        }

        //Closing Client and Server socket

        if(strncmp(sen_msg,"end",3)==0)
        {
            printf("Server Closed.\n");
            printf("Closing client.\n");
            shutdown(sock,2);
            exit(EXIT_SUCCESS);
        }

        strncpy(sen_msg,fr+beg,wn);
        printf("\nCurrent frame\t\t: ");
        printf("%s\n",sen_msg );
        send(sock , sen_msg , 1024 , 0 );



        recv(sock , rcv_msg , 1024 , 0 );

        for (int i = 0; i < strlen(rcv_msg); ++i)
        {
           if ((strncmp(rcv_msg+i,"y",1)==0) || (strncmp(rcv_msg+i,"Y",n)==0))
            {
                beg++;
            }
            else if((strncmp(rcv_msg+i,"n",1)==0) || (strncmp(rcv_msg+i,"N",n)==0))
            {
                break;
            }
        }

        if(strncmp(rcv_msg,"end",3)==0)
        {
            printf("Server Closed.\n");
            printf("Closing client.\n");
            shutdown(sock,2);
            exit(EXIT_SUCCESS);
        }

        printf("Acknowledgement Recieved \t\t: %s\n",rcv_msg);
    }

    return 0;
}
