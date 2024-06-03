//server.c
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

void convert_to_words(char *num, char *words);

int main() 
{
    int fifo_fd;
    char buffer[BUFFER_SIZE];

    
    if (mkfifo(FIFO_NAME, 0666) == -1) 
    {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    printf("Сервер очікує на клієнтів...\n");

    // Открытие именованного канала для чтения
    fifo_fd = open(FIFO_NAME, O_RDONLY);
    if (fifo_fd == -1) 
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) 
    {
        
        if (read(fifo_fd, buffer, BUFFER_SIZE) > 0) 
        {
            char words[BUFFER_SIZE] = {0};
            convert_to_words(buffer, words);
            printf("Прийняте число: %s\n", buffer);
            printf("Число прописом: %s\n", words);
        }
    }

    // Закрытие и удаление именованного канала
    close(fifo_fd);
    unlink(FIFO_NAME);

    return 0;
}

void convert_to_words(char *num, char *words) 
{
    // Простейшие числовые слова
    char *single_digits[] = {"нуль", "один", "два", "три", "чотири", "п'ять", "шість", "сім", "вісім", "дев'ять"};
    char *two_digits[] = {"", "десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п'ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев'ятнадцять"};
    char *tens_multiple[] = {"", "", "двадцять", "тридцять", "сорок", "п'ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев'яносто"};

    // Проверка знака числа
    char temp[BUFFER_SIZE] = {0};
    strcpy(temp, num);

    if (temp[0] == '-') 
    {
        strcat(words, "мінус ");
        memmove(temp, temp + 1, strlen(temp));
    }

    // Разделение на целую и дробную части
    char *int_part_str = strtok(temp, ".");
    char *frac_part_str = strtok(NULL, ".");

    // Обработка целой части
    int int_part = atoi(int_part_str);
    int len = strlen(int_part_str);
    for (int i = 0; i < len; i++) {
        int digit = int_part_str[i] - '0';
        strcat(words, single_digits[digit]);
        if (i == len - 1) 
        {
            strcat(words, " ");
        } 
        else 
        {
            strcat(words, " ");
        }
    }

    strcat(words, "цілих ");

    // Обработка дробной части
    if (frac_part_str != NULL) 
    {
        int len_frac = strlen(frac_part_str);
        for (int i = 0; i < len_frac; i++) 
        {
            int digit = frac_part_str[i] - '0';
            strcat(words, single_digits[digit]);
            if (i == len_frac - 1) 
            {
                strcat(words, " сотих");
            } else {
                strcat(words, " ");
            }
        }
    } 
    else 
    {
        strcat(words, single_digits[0]);
    }
}
