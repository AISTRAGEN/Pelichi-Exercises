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
  int number;

  do 
  {
    std::cout << "\nМеню:" << std::endl;
        std::cout << "1. Додати елементи до стеку" << std::endl;
        std::cout << "2. Видалити елементи зі стеку" << std::endl;
        std::cout << "3. Вивести стек" << std::endl;
        std::cout << "0. Вийти з програми" << std::endl;
        std::cin >> number;

switch (number)
{
case 1:
std::cout << "Введіть елементи в стек (максимальний розмір):" << max_size << std::endl;
std::cout << "Для того аби закінчити вивід просто напишіть 'y' " << std::endl;

  for(int i = 0; i < max_size; ++i)
  {
    std::string input;
    std::cout << "Елемент " << i + 1 << ": ";
    std::cin >> input;
    if(input == "y")
    {
      break;
    }
    else
    {
      int value = std::stoi(input);
      pushSt(&stack, value);
    }
  }
  break;

case 2:
int popElements;
std::cout << "Введіть скільки елементів ви хочете видалити зі стеку" << std::endl;
std::cin >> popElements;

for(int i = 0; i < popElements; ++i)
{
 popSt(&stack);
}
break;

case 3:
printStack(&stack, printStackValue);
break;

case 4:
peekSt(&stack);
break;

case 0:
std::cout << "Вихід з програми" << std::endl;
exit(0);
break;

default:
std::cout << "Невірний вибір, спробуйте ще раз" << std::endl;
  break;
}
  }
  while(number != 0);
  {
   return 0;
  }
  
}
