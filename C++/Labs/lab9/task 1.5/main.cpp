#include <iostream>

class MyClass 
{
private:
    static int totalSum; // Закрите статичне поле для зберігання суми всіх елементів даних

    int data; // Закрите поле для даних об'єкту

public:
    // Конструктор з одним параметром
    MyClass(int value) : data(value) 
    {
        totalSum += value; // Додавання значення до загальної суми при створенні об'єкта
    }

    // Гетер для значення даних об'єкту
    int getData() const 
    {
        return data;
    }

    // Статичний метод для отримання суми всіх елементів даних
    static int getTotalSum() 
    {
        return totalSum;
    }
};

// Ініціалізація статичного поля класу
int MyClass::totalSum = 0;

int main() 
{
    // Створення декількох об'єктів класу MyClass
    MyClass obj1(5);
    MyClass obj2(10);
    MyClass obj3(15);

    // Виведення суми всіх елементів даних
    std::cout << "Загальна сума всіх елементів даних: " << MyClass::getTotalSum() << std::endl;

    return 0;
}
