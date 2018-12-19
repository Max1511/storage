#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	int fd;
	char buffer[100];
	unlink("fifo"); 
	
	if ((fd = open("fifo", O_WRONLY)) < 0){
        fprintf (stderr, "Error\n");
        return 0;
    }
    printf ("Write Message:\n");
    fscanf (stdin, "%s", buffer);
    write (fd, buffer, strlen(buffer));
	printf ("Sended\n");
    close(fd);
	return 0;
}
