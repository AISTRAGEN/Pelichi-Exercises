#include <iostream>

 const int max = 10;


struct Queue
{
    int que[max];
    int head;
    int tail;
};

int init(Queue *pointer)
{
 pointer->head = 1;
 pointer->tail = 0;
}

int insert(Queue *pointer, int value)
{
    std::cout << "Запишіть елементи в чергу" << std::endl;
for(int i = 0; i < max; i++)
{
    if (i < max)
    {
        
    }
    std::cout << "Елемент" << i + 1 << ": " << std::endl;
    pointer->que[pointer->tail] = value;
}

}

int main()
{
    //ДОДАВАННЯ ЕЛЕМЕНТІВ ДО ЧЕРГИ
  std::cout << "Запишіть елементи в чергу" << std::endl;
  for (int i = 0; i < max; i++)
  {
    std::cout << "Елемент" << i + 1 << ": " << std::endl;
    
  }
 
 // ------------------------------------


}
/*Створити функцію додавання елементу в чергу insert. Параметрами функції є покажчик на структуру Queue, та значення, яке додається до структури value. 
Функція має збільшувати на одиницю покажчик tail і додавати значення у масив que. 
Передбачити ситуацію, коли значення покажчика перевищує максимальне значення масиву.  */