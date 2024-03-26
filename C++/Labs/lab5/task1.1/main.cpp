#include <iostream>
#include <cmath>
using namespace std;
// Функція для знаходження мінімального елементу
double findMin(const double arr[], int size) {
    double minElement = arr[0];
    for (int i = 1; i < size; ++i) {
        minElement = min(minElement, arr[i]);
    }
    return minElement;
}

// Функція для знаходження максимального елементу
double findMax(const double arr[], int size) {
    double maxElement = arr[0];
    for (int i = 1; i < size; ++i) {
        maxElement = max(maxElement, arr[i]);
    }
    return maxElement;
}

int main() {
    const int N = 5;
    double myArray[N] = { -44.5, 500.2, 101.8, 88.7, 777.3 };

    double minElement = findMin(myArray, N);
    double maxElement = findMax(myArray, N);

    double sum = minElement + maxElement;
   cout << "Sum om minimum and maximum elements " << sum << endl;

    return 0;
}
