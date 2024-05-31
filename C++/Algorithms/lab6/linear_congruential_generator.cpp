#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
// Функція для отримання множника з масиву
double dGet_A(int iNumber) 
{
    std::vector<double> a = {1.1, 5.2, 9.3, 4.4, 3.5, 7.6, 0.7, 2.8, 8.9, 6.0};
    return a[iNumber % 10];
}

// Головна програма
int main() {
    // Задати змінні
    int initialValue = 7;  // Початкове значення
    const int increment = 65;  // Значення інкременту
    int numToGenerate = 10;  // Кількість величин, які необхідно згенерувати

    double m = 100.0;  // Модуль, бажано великий

    double Xn = initialValue;  // Початкове значення послідовності

    // Цикл генерації псевдовипадкових чисел
    for (int i = 0; i < numToGenerate; ++i) 
    {
        // Реалізація формули (2)
        double a = dGet_A(i);
        Xn = fmod(a * Xn + increment, m);

        // Реалізація формули (3)
        double randomValue = Xn / m;

        // Вивід на консоль згенерованого числа
        std::cout << "Generated random number " << i + 1 << ": " << std::setprecision(5) << randomValue << std::endl;
    }

    return 0;
}
