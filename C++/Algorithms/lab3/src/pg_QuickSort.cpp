#include <iostream>
#include <algorithm>

int partition(int list[], int start, int pivot) 
{
    int pivotValue = list[pivot];
    int i = start - 1;
    int j = start;

    while (j < pivot) 
    {
        if (list[j] <= pivotValue) 
        {
            i++;
            std::swap(list[i], list[j]);
        }
        j++;
    }
    std::swap(list[i + 1], list[pivot]);
    return i + 1;
}




int main() 
{
    const int listLength = 6;
    int list[listLength] = {5, 3, 1, 4, 2, 8};
    
   
    int result = partition(list, 0, listLength - 1); 
    
    std::cout << "Результат розділення: " << result << std::endl;
    
    return 0;
}
