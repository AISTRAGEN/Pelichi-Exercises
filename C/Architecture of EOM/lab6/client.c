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
    int sock = 0; // инициализация переменной для сокета
    struct sockaddr_in serv_addr; // инициализация структуры для адреса сервера
    char buffer[BUFFER_SIZE] = {0}; // инициализация буфера для данных

    // Создание сокета
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET; // установка семейства адресов на IPv4
    serv_addr.sin_port = htons(PORT); // установка порта сервера

    // Преобразование IP адреса
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) 
    {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Подключение к серверу
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    while (1) 
    {
        printf("Введите число со знаком и плавающей точкой: ");
        fgets(buffer, BUFFER_SIZE, stdin); // считывание введенной строки
        buffer[strcspn(buffer, "\n")] = '\0';  // удаление символа новой строки

        // Отправка данных на сервер
        if (send(sock, buffer, strlen(buffer), 0) == -1) { // отправка данных
            perror("send");
            close(sock); // закрытие сокета
            exit(EXIT_FAILURE);
        }
    }

    close(sock); // закрытие сокета

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 100

void convert_to_words(char *num, char *words); // объявление функции преобразования числа в слова

int main() 
{
    int server_fd, new_socket; // инициализация переменных для сокета сервера
    struct sockaddr_in address; // инициализация структуры для адреса сервера
    int opt = 1; // инициализация опции
    int addrlen = sizeof(address); // установка длины адреса
    char buffer[BUFFER_SIZE] = {0}; // инициализация буфера для данных

   
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) // создание сокета
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) // установка опций сокета
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET; // установка семейства адресов на IPv4
    address.sin_addr.s_addr = INADDR_ANY; // установка адреса на localhost
    address.sin_port = htons(PORT); // установка порта сервера

    // привязка сокета к адресу и порту
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // прослушивание подключений
    if (listen(server_fd, 3) < 0) 
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Сервер ожидает клиентов...\n");

    // принятие подключения от клиента
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) 
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Получение данных от клиента
        if (read(new_socket, buffer, BUFFER_SIZE) > 0) 
        {
            char words[BUFFER_SIZE] = {0};
            convert_to_words(buffer, words); // преобразование числа в слова
            printf("Принято число: %s\n", buffer); // вывод принятого числа
            printf("Число словами: %s\n", words); // вывод числа словами
        }
    }

    return 0;
}

void convert_to_words(char *num, char *words) 
{
    // массивы для преобразования числа в слова
    char *single_digits[] = {"нуль", "один", "два", "три", "чотири", "п'ять", "шість", "сім", "вісім", "дев'ять"};
    char *two_digits[] = {"", "десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п'ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев'ятнадцять"};
    char *tens_multiple[] = {"", "", "двадцять", "тридцять", "сорок", "п'ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев'яносто"};

    int is_negative = 0;
    if (num[0] == '-') // проверка на отрицательное число
    {
        is_negative = 1;
        num++; // пропуск знака минус
    }

    // разделение на целую и дробную части
    char *int_part_str = strtok(num, ".");
    char *frac_part_str = strtok(NULL, ".");

    int int_part = atoi(int_part_str); // преобразование целой части в число
    if (is_negative) {
        strcat(words, "мінус "); // добавление слова "минус" если число отрицательное
    }
    if (int_part == 0) 
    {
        strcat(words, single_digits[0]); // если целая часть

