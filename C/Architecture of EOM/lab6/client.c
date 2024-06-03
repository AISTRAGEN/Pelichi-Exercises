// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 100

int main() 
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Создание сокета
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Преобразование IP адреса
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) 
    {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    while (1) 
    {
        printf("Введите число со знаком и плавающей точкой: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  

        // Отправка данных на сервер
        if (send(sock, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            close(sock);
            exit(EXIT_FAILURE);
        }
    }

    close(sock);

    return 0;
}