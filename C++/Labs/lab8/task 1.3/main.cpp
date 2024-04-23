#include <iostream>

// Структура для опису міста
struct City
{
    char name[30];
    char country[30];
    char region[30];
    int population;
};

// Сортування за населенням
// Замість модифікації масиву міст, змінюємо масив вказівників
void sortByPopulation(City** arr, int size)
{
    bool mustSort; // повторюємо сортування 
                   // якщо mustSort дорівнює true
    do
    {
        mustSort = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i]->population > arr[i + 1]->population)
                // Обманюємо елементи
            {
                City* temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                mustSort = true;
            }
        }
    } 
    while (mustSort);
}

// Виведення даних про місто.
// Для підвищення ефективності використовуємо посилання
// на константний об'єкт
void printCity(const City& city)
{
    std::printf("Мiсто: %s. Країна: %s. Регіон: %s. Населення: %d\n",
        city.name, city.country, city.region, city.population);
}

// Виведення даних про всі міста.
// Доступ до міст здійснюємо через масив указівників
void pintCities(City** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printCity(*arr[i]);
    }
    std::cout << "\n";
}

// Виведення даних про міста,
// які знаходяться в певному регіоні
void printIf(City cities[], int size, const char* region)
{
    for (int i = 0; i < size; i++)
    {
        if (std::strcmp(cities[i].region, region) == 0) {
            printCity(cities[i]);
        }
    }
}

int main()
{
    std::system("chcp 1251 > nul");
    const int n = 4;
    
    // Створюємо і заповнюємо масив міст:
    City cities[n] = { 
        { "Харкiв", "Україна", "Харкiвська область", 1421125 },
        { "Полтава", "Україна", "Полтавська область", 284942 },
        { "Лозова", "Україна", "Харкiвська область", 54618 },
        { "Суми", "Україна", "Сумська область", 264753 }
    };
    
    // Створюємо і заповнюємо масив указівників:
    City* pointers[n];
    for (int i = 0; i < n; i++)
    {
        pointers[i] = &cities[i];
    }

    pintCities(pointers, n);
    sortByPopulation(pointers, n);
    pintCities(pointers, n);
    printIf(cities, n, "Харкiвська область");
    return 0;
}