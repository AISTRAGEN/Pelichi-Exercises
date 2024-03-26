#include <iostream>
#include <cmath>

const int MAX_ROWS = 5; // Задайте бажану кількість рядків
const int MAX_COLS = 4; // Задайте бажану кількість стовпців

// Функція для перетворення елементів масиву в їх абсолютні значення
void transformArray(int arr[MAX_ROWS][MAX_COLS]) 
{
	for (int i = 0; i < MAX_ROWS; ++i) 
	{
		for (int j = 0; j < MAX_COLS; ++j) 
		{
			arr[i][j] = abs(arr[i][j]);
		}
	}
}

// Функція для створення та заповнення одновимірного масиву чисел типу double
// мінімальними елементами колонок вихідного масиву
void fillDoubleArray(double result[], int arr[MAX_ROWS][MAX_COLS]) 
{
	for (int j = 0; j < MAX_COLS; ++j) 
	{
		double minElement = static_cast<double>(arr[0][j]); // Початкове значення - перший елемент колонки

		for (int i = 1; i < MAX_ROWS; ++i)
		{
			minElement = std::min(minElement, static_cast<double>(arr[i][j]));
		}

		result[j] = minElement;
	}
}

int main() {
	int originalArray[MAX_ROWS][MAX_COLS];

	// Введення елементів двовимірного масиву
	std::cout << "Enter the elements of a two-dimensional array " << MAX_ROWS << "x" << MAX_COLS << ":\n";
	for (int i = 0; i < MAX_ROWS; ++i) 
	{
		for (int j = 0; j < MAX_COLS; ++j) 
		{
			std::cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
			std::cin >> originalArray[i][j];
		}
	}

	// Перетворення елементів вихідного масиву
	transformArray(originalArray);

	// Створення та заповнення одновимірного масиву чисел типу double
	double resultArray[MAX_COLS];
	fillDoubleArray(resultArray, originalArray);

	// Виведення елементів обох масивів
	std::cout << "\nElements of a converted two-dimensional array:\n";
	for (int i = 0; i < MAX_ROWS; ++i) 
	{
		for (int j = 0; j < MAX_COLS; ++j) 
		{
			std::cout << originalArray[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\nElements of a one-dimensional array of type double:\n";
	for (int j = 0; j < MAX_COLS; ++j) 
	{
		std::cout << resultArray[j] << " ";
	}

	return 0;
}
