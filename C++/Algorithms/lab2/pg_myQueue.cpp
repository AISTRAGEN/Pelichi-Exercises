#include <iostream>

const int max = 5;

struct Queue
{
    int que[max];
    int head;
    int tail;
};

void init(Queue *pointer)
{
    pointer->head = 1;
    pointer->tail = 0;
}

void insert(Queue *pointer, int value)
{
    if (pointer->tail >= max)
    {
        std::cout << "Перевищено максимальний розмір черги" << std::endl;
        return;
    }

    pointer->tail++;
    pointer->que[pointer->tail] = value;
}

int isEmpty(Queue *pointer)
{
    if(pointer->head > pointer->tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print(Queue *pointer)
{
    if (isEmpty(pointer))
    {
        std::cout << "Черга порожня" << std::endl;
        return;
    }

    for (int i = pointer->head; i <= pointer->tail; i++) 
    {
        std::cout << pointer->que[i] << " ";
    }
    std::cout << std::endl;
}

int remove(Queue *pointer)
{
    if (isEmpty(pointer))
    {
        std::cout << "Черга порожня" << std::endl;
        return -1; // Повертаємо значення за замовчуванням для позначення порожньої черги
    }

    int removedValue = pointer->que[pointer->head];
    pointer->head++;

    return removedValue;
}

int main()
{
    Queue myQueue;
    int number;

    init(&myQueue);

    do
    {
        std::cout << "1.Додати елементи в чергу" << std::endl;
        std::cout << "2.Вивести елементи" << std::endl;
        std::cout << "3.Видалити елементи" << std::endl;
        std::cin >> number;

        switch (number)
        {
        case 1:
            int value;
            std::cout << "Введіть значення для додавання в чергу: ";
            std::cin >> value;
            insert(&myQueue, value);
            break;

        case 2:
            print(&myQueue);
            break;

        case 3:
            remove(&myQueue);
            break;

        case 0:
            std::cout << "Завершення програми" << std::endl;
            break;

        default:
            std::cout << "Невірний вибір, спробуйте ще раз" << std::endl;
            break;
        }

    } while (number != 0);

    return 0;
}
