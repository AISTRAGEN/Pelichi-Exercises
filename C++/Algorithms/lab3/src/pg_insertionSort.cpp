#include <iostream>
#include <algorithm>

int insertionSort(int* list, int listLength)
{
    int swaps = 0; 

    for (int i = 1; i < listLength; ++i)
    {
        int j = i - 1;
        while (j >= 0 && list[j] > list[j + 1])
        {
            std::swap(list[j], list[j + 1]); 
            swaps++; 
            j--;
        }
    }
    return swaps;
}

int main()
{
    const int listLength = 8;
    int list[listLength]{35, 12, 28, 47, 20, 31, 50, 42};

    int swaps = insertionSort(list, listLength);

    std::cout << "Масив після сортування: ";
    for (int i = 0; i < listLength; ++i)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Кількість обмінів: " << swaps << std::endl;

    return 0;
}
