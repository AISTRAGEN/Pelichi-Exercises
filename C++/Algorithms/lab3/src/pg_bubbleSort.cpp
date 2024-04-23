#include <iostream>
#include <algorithm>

void bubbleSort(int* ptr, int listLength)
{
    bool swapped = true; 
    while (swapped)
    {
        swapped = false; 
        for (int i = 0; i < listLength - 1; ++i)
        {
            if (ptr[i] > ptr[i + 1])
            {
                
                std::swap(ptr[i], ptr[i + 1]);
                swapped = true; 
            }
        }
        --listLength; 
    }
}

int main()
{
    const int listLength = 5;
    int list[listLength]{5, 3, 1, 4, 2};

    
    std::cout << "Початковий масив: ";
    for (int i = 0; i < listLength; ++i)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    
    bubbleSort(list, listLength);

    
    std::cout << "Відсортований масив: ";
    for (int i = 0; i < listLength; ++i)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
