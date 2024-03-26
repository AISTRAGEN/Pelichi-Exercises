#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void fillMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) 
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = (rand() % 100000) / 1000.;
		}
	}
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << matrix[i][j];
			if (j < cols - 1)
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void multiplyMatrices(int matrixA[MAX_ROWS][MAX_COLS], int rowsA, int colsA,
	int matrixB[MAX_ROWS][MAX_COLS], int rowsB, int colsB,
	int result[MAX_ROWS][MAX_COLS])
{
	for (int i = 0; i < rowsA; ++i)
	{
		for (int j = 0; j < colsB; ++j)
		{
			result[i][j] = 0;
			for (int k = 0; k < colsA; ++k)
			{
				result[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}

int main() 
{
	srand(time(0));
	int rows1, cols1, rows2, cols2;
	std::cout << "Enter the number of rows and columns for matrix A: ";
	std::cin >> rows1 >> cols1;
	std::cout << "Enter the number of rows and columns for matrix B: ";
	std::cin >> rows2 >> cols2;
	if (rows1 > MAX_ROWS || rows2 > MAX_COLS || cols1 > MAX_ROWS || cols2 > MAX_COLS)
	{
		std::cout << "Error " << MAX_ROWS << "x" << MAX_COLS << "." << std::endl;
		return 1;
	}

	if (cols1 != rows2)
	{
		std::cout << "Error: Unable to multiply matrices:" << std::endl;
		return 2;
	}
	int matrixA[MAX_ROWS][MAX_COLS];
	int matrixB[MAX_ROWS][MAX_COLS];
	int result[MAX_ROWS][MAX_COLS];
	fillMatrix(matrixA, rows1, cols1);
	fillMatrix(matrixB, rows2, cols2);
	std::cout << "Matrix A:" << std::endl;
	printMatrix(matrixA, rows1, cols1);
	std::cout << "Matrix B:" << std::endl;
	printMatrix(matrixB, rows2, cols2);
	multiplyMatrices(matrixA, rows1, cols1, matrixB, rows2, cols2, result);
	std::cout << "Result of matrix multiplication:" << std::endl;
	printMatrix(result, rows1, cols2);

	return 0;
}
