#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    char *hostname = "www.roehampton.ac.uk";
    char ip[100];
    struct hostent *he;
    struct in_addr *addr;
    int socket_desc;
    struct sockaddr_in server;
    int status;

    // Resolve the host name
    // *** COMPLETE ME ***

    if (he == NULL)
    {
        printf("Get hostname failed\n");
        return 1;
    }

    // Get first address and convert to in_addr type
    // *** COMPLETE ME ***
    // Copy the address into IP buffer using inet_ntoa
    // *** COMPLETE ME ***
    printf("%s resolved to: %s\n", hostname, ip);

    // Create the socket
    // *** COMPLETE ME ***

    if (socket_desc == -1)
    {
        printf("Could not create socket\n");
    }
    else
    {
        printf("Socket created\n");
    }

    // Set the address of the sockaddr_in structure
    // *** COMPLETE ME ***
    // Set the protocol family of the sockaddr_in structure
    // *** COMPLETE ME ***
    // Set the port of the sockaddr_in structure
    // *** COMPLETE ME ***

    // Connect to the web server
    // *** COMPLETE ME ***

    if (status < 0)
    {
        printf("Connection error\n");
        return 1;
    }
    
    printf("Connected\n");

    return 0;
}