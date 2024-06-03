#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 100

void convert_to_words(char *num, char *words);

int main() 
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

   
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    
    if (listen(server_fd, 3) < 0) 
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Сервер ожидает клиентов...\n");

    
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
            convert_to_words(buffer, words);
            printf("Принято число: %s\n", buffer);
            printf("Число словами: %s\n", words);
        }
    }

    return 0;
}

void convert_to_words(char *num, char *words) 
{
    
    char *single_digits[] = {"нуль", "один", "два", "три", "чотири", "п'ять", "шість", "сім", "вісім", "дев'ять"};
    char *two_digits[] = {"", "десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п'ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев'ятнадцять"};
    char *tens_multiple[] = {"", "", "двадцять", "тридцять", "сорок", "п'ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев'яносто"};

   
    int is_negative = 0;
    if (num[0] == '-') 
    {
        is_negative = 1;
        num++; 
    }

    
    char *int_part_str = strtok(num, ".");
    char *frac_part_str = strtok(NULL, ".");

    
    int int_part = atoi(int_part_str);
    if (is_negative) {
        strcat(words, "мінус ");
    }
    if (int_part == 0) 
    {
        strcat(words, single_digits[0]); 
    } 
    else 
    {
        if (int_part >= 100) 
        {
            strcat(words, "сто ");
            int_part -= 100;
        }
        if (int_part >= 20) 
        {
            strcat(words, tens_multiple[int_part / 10]);
            strcat(words, " ");
            int_part %= 10;
        }
        if (int_part >= 10) 
        {
            strcat(words, two_digits[int_part]);
        } 
        else 
        {
            strcat(words, single_digits[int_part]);
        }
    }
    strcat(words, " цілих ");

    // Обработка дробной части
    if (frac_part_str != NULL) 
    {
        int frac_part = atoi(frac_part_str);
        if (frac_part > 0) 
        {
            strcat(words, "і ");
            if (frac_part < 10) 
            {
                strcat(words, single_digits[frac_part]);
            } 
            else 
            {
                strcat(words, tens_multiple[frac_part / 10]);
                strcat(words, " ");
                frac_part %= 10;
                strcat(words, single_digits[frac_part]);
            }
            strcat(words, " сотих");
        }
    } 
    else 
    {
        strcat(words, single_digits[0]); 
    }
}


