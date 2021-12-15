#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/net.h>
#include <linux/in.h>

static int __init init_function(void)
{
    // The socket that will listen for incoming connections
    struct socket *sock;
    // The client that has connected
    struct socket *client;
    // The address data structure defining where we listen
    struct sockaddr_in server;
    // This is different. Kernel sockets send messages.
    // Message is used primarily in UDP.
    struct msghdr msg;
    // kvec is the data we will send - it has buffer and
    // size
    struct kvec iov;
    int status;
    int port = 5000;
    // The buffer we will send/receive on
    char buffer[100];

    // First create the server socket.
    // Use sock_create now.
    // PF_INET same as AF_INET
    // IPPROTO_TCP means TCP
    status = sock_create(PF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
    // Create the address data structure to listen to.
    // Pretty much identical to previous version.
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    // Use kernel_bind rather than just bind, but 
    // otherwise identical
    status = kernel_bind(sock, (struct sockaddr*)&server, sizeof(struct sockaddr_in));
    // Use kernel_listen rather than listen, but otherwise
    // identical
    status = kernel_listen(sock, 3);
    // Use kernel_accept rather than accept. Takes a 
    // pointer to the new socket to be filled.
    status = kernel_accept(sock, &client, 0);
    // Now clear all the buffers
    memset(buffer, 0, 100);
    memset(&msg, 0, sizeof(msg));
    // Create the data packet to send.
    // - pointer to the buffer in iov_base
    // - length of the buffer in bytes.
    iov.iov_base = buffer;
    iov.iov_len = 100;
    // Call kernel_recvmsg
    // - pointer to socket to receive message on
    // - pointer to msghdr - not used in TCP
    // - pointer to data packet
    // - Number of clients and packets
    // - size of data
    // - Any flags (we ignore)
    status = kernel_recvmsg(client, &msg, &iov, 1, 100, 0);
    // Print the received message - now in iov_base of
    // packet
    printk(KERN_INFO "%s", (char*)iov.iov_base);
    // Clear all the buffers again
    memset(buffer, 0, 100);
    memset(&msg, 0, sizeof(msg));
    // Copy a message into the buffer
    strcpy(buffer, "Whoop!");
    // Set the data packet to send
    iov.iov_base = buffer;
    iov.iov_len = strlen(buffer);
    // Call kernel_sendmsg
    // - pointer to socket to send to
    // - pointer to msghdr - not used in TCP
    // - pointer to data packet
    // - number of clients and packets
    // - size of the data sent.
    status = kernel_sendmsg(client, &msg, &iov, 1, strlen(buffer));

    // Now shutdown the client socket.
    // This is the same as close.
    status = kernel_sock_shutdown(client, SHUT_RDWR);
    // Shutdown the server socket
    status = kernel_sock_shutdown(sock, SHUT_RDWR);
    // Release the server socket
    sock_release(sock);

    return 0;
}

static void __exit exit_function(void)
{
    
}

module_init(init_function);
module_exit(exit_function);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Chalmers <kevin.chalmers@roehampton.ac.uk>");
MODULE_DESCRIPTION("Device driver");