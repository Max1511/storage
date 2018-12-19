#include <netdb.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <string.h>

int main (int argc, char* argv[])
{
        struct hostent *h;
        h=gethostbyname (argv[1]);

        if (NULL == h) {
                printf("Error of hostent\n");
                return -1;
        }

        int fd;
        char *fifo = "buffer_channel_4";

        mkfifo (fifo, 0666);

        if ((fd = open(fifo, O_WRONLY)) < 0) {
                fprintf (stderr, "Error of O_WRONLY\n");
                return -1;
        }

        printf ("Send...\n");

        int i=0;
        while (NULL != h->h_addr_list[i]){
                struct in_addr* tmp = (struct in_addr*) h->h_addr_list[i];
                write (fd, h->h_addr_list[i], strlen(h->h_addr_list[i]));
                i++;
        }

        close (fd);
        unlink (fifo);
        return 0;
}

