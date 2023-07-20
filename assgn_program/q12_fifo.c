#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main()
{
    char *fifo_name = "/tmp/myfifo";
    char buffer[BUFFER_SIZE];

    
    mkfifo(fifo_name, 0666);

    
    int fd = open(fifo_name, O_WRONLY);

    
    write(fd, "Hello, world!", sizeof("Hello, world!"));

    
    close(fd);

    
    fd = open(fifo_name, O_RDONLY);

    
    int num_bytes = read(fd, buffer, BUFFER_SIZE);
    buffer[num_bytes] = '\0';

    
    printf("Received message: %s\n", buffer);

    
    close(fd);

    
    unlink(fifo_name);

    return 0;
}

