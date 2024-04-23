#include <iostream>
#include <algorithm>

int findSmallestPosition(int* list, int listLength, int startPosition)
{
  int smallestPosition  =  startPosition;

 for(int i = startPosition; i < listLength; ++i)
 {
        if (list[i] < list[smallestPosition]) 
        {
            smallestPosition = i;
        }

 }

  return smallestPosition;
}

void selectionSort(int* list, int listLength) 
{
    for (int i = 0; i < listLength - 1; ++i) 
    {
        int smallestPosition = findSmallestPosition(list, listLength, i);
        std::swap(list[i], list[smallestPosition]);
    }
}

int main()
{
    const int listLength = 5;
  int list[listLength]{2,1,3,4,5};
  
 selectionSort(list, listLength);

    std::cout << "Відсортований масив: ";
    for (int i = 0; i < listLength; ++i) 
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
