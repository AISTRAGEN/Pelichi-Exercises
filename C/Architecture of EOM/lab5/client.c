//client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"
#define BUFFER_SIZE 100

int main() 
{
    int fifo_fd;
    char buffer[BUFFER_SIZE];

    
    fifo_fd = open(FIFO_NAME, O_WRONLY);
    if (fifo_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) 
    {
        printf("Введіть число зі знаком і плаваючою точкою: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  
                                                                  

        // Отправка данных в канал
        if (write(fifo_fd, buffer, strlen(buffer) + 1) == -1) 
        {
            perror("write");
            close(fifo_fd);
            exit(EXIT_FAILURE);
        }
    }

   
    close(fifo_fd);

    return 0;
}
