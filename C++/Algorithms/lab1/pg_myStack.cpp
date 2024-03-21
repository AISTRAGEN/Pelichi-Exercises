#include <cstdlib>
#include <iostream>

const int max_size = 10;

struct Stack_tag 
{
  int data[max_size];
  int size;
};

void pushSt(Stack_tag *stack, int value) 
{
  if (stack->size < max_size) 
  {
    stack->data[stack->size++] = value;
  } 
  else 
  {
    exit(0);
  }
}

int popSt(Stack_tag *stack) 
{
  if (stack->size > 0) 
  {
    return stack->data[--(stack->size)];
  } 
  else 
  {
    exit(0);
  }
}

int peekSt(Stack_tag *stack) 
{
  if (stack->size > 0) 
  {
    return stack->data[stack->size - 1];
  } 
  else
  {
    exit(0);
  }
}

void printStackValue(char symbol) 
{ 
  std::cout << symbol; 
}

void printStack(Stack_tag *stack, void (*printStackValue)(char)) 
{
  printStackValue('|');
  for (int i = 0; i < stack->size; ++i) 
  {
    std::cout << stack->data[i];
    printStackValue('|');
  }
}

int main() 
{
  Stack_tag stack;
  stack.size = 0;

  std::cout << "Ця програма показує як працює стек" << std::endl;
  std::cout << "Запишіть елементи в стек" << std::endl;

  for (int i = 0; i < max_size; i++)
   {
    int value;
    std::cout << "Елемент " << i + 1 << ": ";
    std::cin >> value;
    pushSt(&stack, value);
  }

  std::cout << "Тепер напишіть скільки елементів ви хочете взяти зі стеку" << std::endl;
  int popElements;
  std::cin >> popElements;

  std::cout << "Ваш стек виглядає ось так:" << std::endl;
  printStack(&stack, printStackValue);
  std::cout << std::endl;

  for (int i = 0; i < popElements; ++i)
   {
    popSt(&stack);
    std::cout << "Стек після вилучення " << i + 1 << " елементу: " << std::endl;
    int topValue = peekSt(&stack);
    printStack(&stack, printStackValue);
    std::cout << " - Значення верхнього елемента після операції: " << topValue << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
