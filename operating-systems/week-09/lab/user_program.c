#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define MY_CALL _IO('X', 0)

int main(int argc, char **argv)
{
    int fd;
    char *str[80];
    // Open the device in O_RDWR mode
    // *** COMPLETE ME ***
    // Use ioctl to send MY_CALL message
    // *** COMPLETE ME ***
    printf("Received %s from driver\n", str);
    // Close the device
    // *** COMPLETE ME ***
    return 0;
}