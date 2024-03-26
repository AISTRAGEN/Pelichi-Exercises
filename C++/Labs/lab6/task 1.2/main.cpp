#include <iostream>
#include <ctime>

void fillMatrix(double** matrix, int rows, int cols) 
{
    srand(time(nullptr));
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            matrix[i][j] = static_cast<double>(rand()) / RAND_MAX * 100.0;
        }
    }
}

void multiplyMatrices(double** A, double** B, double** result, int rows1, int cols1, int cols2) 
{
    for (int i = 0; i < rows1; ++i) 
    {
        for (int j = 0; j < cols2; ++j) 
        {
            result[i][j] = 0.0;
            for (int k = 0; k < cols1; ++k) 
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(double** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() 
{
    int rows1, cols1, rows2, cols2;
    std::cout << "Enter the dimensions of the first matrix (rows and columns): ";
    std::cin >> rows1 >> cols1;
    std::cout << "Enter the dimensions of the second matrix (rows and columns): ";
    std::cin >> rows2 >> cols2;

    if (cols1 != rows2) 
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    // Створення двовимірних масивів (матриць) в динамічній пам'яті
    double** matrix1 = new double* [rows1];
    double** matrix2 = new double* [rows2];
    double** resultMatrix = new double* [rows1];
    for (int i = 0; i < rows1; ++i) {
        matrix1[i] = new double[cols1];
        resultMatrix[i] = new double[cols2];
    }
    for (int i = 0; i < rows2; ++i) {
        matrix2[i] = new double[cols2];
    }

    
    fillMatrix(matrix1, rows1, cols1);
    fillMatrix(matrix2, rows2, cols2);

 
    multiplyMatrices(matrix1, matrix2, resultMatrix, rows1, cols1, cols2);

    std::cout << "Result" << std::endl;
    printMatrix(resultMatrix, rows1, cols2);

    for (int i = 0; i < rows1; ++i) {
        delete[] matrix1[i];
        delete[] resultMatrix[i];
    }
    for (int i = 0; i < rows2; ++i) {
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] resultMatrix;

    return 0;
}
