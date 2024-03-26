#include <iostream>
#include <fstream>
#include <ctime> 

double findMin(const double arr[], int size)
{
    double minElement = arr[0];
    for (int i = 1; i < size; ++i) 
    {
        minElement = std::min(minElement, arr[i]);
    }
    return minElement;
}


double findMax(const double arr[], int size)
{
    double maxElement = arr[0];
    for (int i = 1; i < size; ++i)
    {
        maxElement = std::max(maxElement, arr[i]);
    }
    return maxElement;
}

int main() 
{
    int N;
    std::cout << "Enter the length of the array:";
    std::cin >> N;

    
    double* myArray = new double[N];

    
    srand(time(nullptr)); 
    for (int i = 0; i < N; ++i)
    {
        myArray[i] = static_cast<double>(rand()) / RAND_MAX * 100.0;
    }

    double minElement = findMin(myArray, N);
    double maxElement = findMax(myArray, N);

  
    double sum = minElement + maxElement;
    std::cout << "The sum of the minimum and maximum elements: " << sum << std::endl;

   
    std::ofstream outFile("result.txt");
    if (outFile.is_open()) 
    {
        outFile << "Minimal element: " << minElement << std::endl;
        outFile << "Maximal element: " << maxElement << std::endl;
        outFile << "Sum: " << sum << std::endl;
        outFile.close();
        std::cout << "Mission complete" << std::endl;
    }
    else 
    {
        std::cout << "Error" << std::endl;
    }

    delete[] myArray;

    return 0;
}
