
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

void Stop (int signalno)
{
        exit(0);
}

int main (int argc, char* argv[])
{
        printf("%d\n", getpid());

        int fd;
        char buffer[100][100];
        char *fifo = "buffer_channel_4";

        mkfifo (fifo, 0666);

        while (1)
        {
                signal (SIGUSR1, Stop);
                if ((fd = open(fifo, O_RDONLY)) < 0) {
                        continue;
                }
                fprintf("Massage:\n");
                int i=0;
                for (i=0; i<100; ++i)
                {
                        read (fd, &buffer[i], 100*100);
                        printf("%s\n", buffer[i]);
                }
        }
		return 0;
}
