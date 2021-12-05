#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *ip = "127.0.0.1";
    int port = 5000;
    struct in_addr *addr;
    int socket_desc;
    struct sockaddr_in server;
    int status;
    char message[2000];
    char server_reply[2000];

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1)
    {
        printf("Could not create socket\n");
    }
    else
    {
        printf("Socket created\n");
    }

    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    status = connect(socket_desc, (struct sockaddr*)&server, sizeof(server));

    if (status < 0)
    {
        printf("Connection error\n");
        return 1;
    }
    
    printf("Connected\n");

    printf("Enter message to send (0 to exit): ");
    fgets(message, sizeof(message), stdin);

    while (message[0] != '0')
    {
        status = send(socket_desc, message, strlen(message), 0);
        if (status < 0)
        {
            printf("Send failed");
            return 1;
        }

        printf("Data sent\n");

        status = recv(socket_desc, server_reply, 2000, 0);

        if (status < 0)
        {
            printf("Receive failed\n");
            return 1;
        }

        printf("Reply received\n");
        printf("%s\n", server_reply);

        printf("Enter message to send (0 to exit): ");
        fgets(message, sizeof(message), stdin);
    }
    
    return 0;
}