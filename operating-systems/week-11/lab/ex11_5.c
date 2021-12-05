#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void* handle_connection(void *arg)
{
    int socket_desc = (int)arg;
    int read_size;
    char buffer[2000];
    char message[2000];

    memset(buffer, 0, 2000);
    // Use recv to receive a message from the client
    // *** COMPLETE ME ***
    
    while (read_size > 0)
    {
        printf("Received: %s\n", buffer);
        memset(message, 0, 2000);
        printf("Enter reply: ");
        fgets(message, sizeof(message), stdin);
        // Send message back to the client
        // *** COMPLETE ME ***

        memset(buffer, 0, 2000);
        // Use recv to receive a message from the client
        // *** COMPLETE ME ***
    }

    // Close the new connection
    // *** COMPLETE ME ***

    // Exit the thread
    // *** COMPLETE ME ***
}

int main(int argc, char **argv)
{
    int socket_desc;
    struct sockaddr_in server;
    int status;
    int port = 5000;
    int new_socket;
    struct sockaddr_in client;
    int size;
    pthread_t handler_thread[10];
    int handler_count = 0;
    int i;
    void *retval;

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

    while (new_socket >= 0 && handler_count < 10)
    {
        printf("Connection successful\n");

        printf("Starting new connection handler\n");

        // Create a new thread using the handle_connection function. Pass the new_socket as a parameter.
        // *** COMPLETE ME ***

        // Accept a new connection
        // *** COMPLETE ME ***
    }

    printf("Shutting down server\n");

    for (i = 0; i < handler_count; ++i)
    {
        // Join thread i
        // *** COMPLETE ME ***
    }

    printf("Exiting...\n");

    // Close the server socket
    // *** COMPLETE ME ***

    return 0;
}