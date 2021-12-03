#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int socket_desc;
    struct sockaddr_in server;
    int status;
    int port = 5000;
    int new_socket;
    struct sockaddr_in client;
    int size;
    char buffer[2000];
    char message[2000];

    // Create a socket
    // *** COMPLETE ME ***

    if (socket_desc == -1)
    {
        printf("Could not create socket\n");
        return -1;
    }

    // Set the family, address and port of the socket
    // *** COMPLETE ME ***

    // Bind the socket
    // *** COMPLETE ME ***

    if (status < 0)
    {
        printf("Failed to create server socket\n");
        return -1;
    }
    printf("Server socket created\n");

    // Listen on the server socket
    // *** COMPLETE ME ***

    printf("Server listening on port %d\n", port);

    size = sizeof(client);
    // Accept a new connection
    // *** COMPLETE ME ***

    while (new_socket >= 0)
    {
        printf("Connection successful\n");

        // Clear the buffer
        memset(buffer, 0, 2000);
        // Use recv to receive a message from the client
        // *** COMPLETE ME ***

        if (status < 0)
        {
            printf("Receive failed\n");
            return 1;
        }

        printf("Server received %s", buffer);

        printf("Enter reply: ");
        fgets(message, sizeof(message), stdin);

        // Send message back to the client
        // *** COMPLETE ME ***

        if (status < 0)
        {
            printf("Send failed\n");
            return 1;
        }

        // Close the new connection
        // *** COMPLETE ME ***

        // Accept a new connection
        // *** COMPLETE ME ***
    }

    // Close the server socket
    // *** COMPLETE ME ***

    return 0;
}