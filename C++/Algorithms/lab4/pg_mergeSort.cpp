#include <iostream>
#include <algorithm>

const int listLength = 10;

void merge(int start, int end, int mid, int list[])
{
    int mergedList[listLength];
    int k = start;
    int j = mid + 1;
    int i = start;
    
    while (i <= mid && j <= end)
    {
        if (list[i] <= list[j])
        {
            mergedList[k++] = list[i++];
        }
        else
        {
            mergedList[k++] = list[j++];
        }
    }

    // Додаємо залишок першого підмасиву, якщо він є
    while (i <= mid)
    {
        mergedList[k++] = list[i++];
    }

    // Додаємо залишок другого підмасиву, якщо він є
    while (j <= end)
    {
        mergedList[k++] = list[j++];
    }
    
    // Копіюємо відсортовані значення з mergedList назад в основний масив list
    for (int i = start; i <= end; ++i)
    {
        list[i] = mergedList[i];
    }
}

void mergeSort(int list[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        std::cout << "mergeSort(" << start << ", " << mid << ")" << std::endl;
        mergeSort(list, start, mid);

        std::cout << "mergeSort(" << mid + 1 << ", " << end << ")" << std::endl;
        mergeSort(list, mid + 1, end);

        std::cout << "merge(" << start << ", " << end << ", " << mid << ")" << std::endl;
        merge(start, end, mid, list);
    }
}

int main()
{
    int list[listLength]{1, 8, 10, 11, 15, 17, 20, 5, 66, 18};
    mergeSort(list, 0, listLength - 1);
    
    std::cout << "Відсортований масив:" << std::endl;
    for (int i = 0; i < listLength; ++i)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
