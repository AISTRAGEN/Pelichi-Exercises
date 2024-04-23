#include <iostream>
#include <algorithm>
void shellSort(int list[], int listLength) 
{
    int step = listLength / 2;

    for (; step > 0; step /= 2) 
    {
        
        for (int i = step; i < listLength; ++i) 
        {
            int j = i;
            
            while (j >= step && list[j - step] > list[j]) 
            {
                
                int temp = list[j];
                list[j] = list[j - step];
                list[j - step] = temp;
                j -= step;
            }
        }
    }
}

int main() 
{
    const int listLength = 8;
    int list[listLength]{35, 12, 28, 47, 20, 31, 50, 42};

    std::cout << "Масив до сортування: ";
    for (int i = 0; i < listLength; ++i) 
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    shellSort(list, listLength);

    std::cout << "Масив після сортування: ";
    for (int i = 0; i < listLength; ++i) 
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
