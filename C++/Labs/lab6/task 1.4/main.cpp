#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void readArraySize(const char* filename, int& rows, int& cols) 
{
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "File opening error: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    file >> rows >> cols;
    file.close();
}

void readArray(const char* filename, int** arr, int rows, int cols) 
{
    std::ifstream file(filename);
    if (!file) 
    {
        std::cerr << "File opening error: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            file >> arr[i][j];
        }
    }
    file.close();
}

void processArray(int** originalArray, int rows, int cols, int** resultArray, int* minValues) {
    // Заповнення resultArray модулями елементів originalArray
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            resultArray[i][j] = abs(originalArray[i][j]);
        }
    }

    // Знаходження мінімальних елементів по колонках та їх запис у minValues
    for (int j = 0; j < cols; ++j) 
    {
        int minElement = resultArray[0][j];
        for (int i = 1; i < rows; ++i) 
        {
            minElement = std::min(minElement, resultArray[i][j]);
        }
        minValues[j] = minElement;
    }
}

void writeArrayToFile(const char* filename, int** arr, int rows, int cols) 
{
    std::ofstream file(filename);
    if (!file) 
    {
        std::cerr << "File opening error: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            file << arr[i][j] << " ";
        }
        file << std::endl;
    }
    file.close();
}

void writeMinValuesToFile(const char* filename, int* minValues, int cols) 
{
   std::ofstream file(filename);
    if (!file) 
    {
        std::cerr << "File opening error: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int j = 0; j < cols; ++j) 
    {
        file << minValues[j] << " ";
    }
    file << std::endl;
    file.close();
}

void freeMemory(int** arr, int rows) 
{
    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() 
{
    const char* inputFilename = "input.txt";
    const char* outputFilename1 = "output1.txt";
    const char* outputFilename2 = "output2.txt";

    int rows, cols;
    readArraySize(inputFilename, rows, cols);

    int** originalArray = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        originalArray[i] = new int[cols];
    }

    readArray(inputFilename, originalArray, rows, cols);

    int** resultArray = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        resultArray[i] = new int[cols];
    }

    int* minValues = new int[cols];

    processArray(originalArray, rows, cols, resultArray, minValues);

    std::cout << "Original Array:\n";
    printMatrix(originalArray, rows, cols);
    
    std::cout << "\nResult Array:\n";
    printMatrix(resultArray, rows, cols);

    writeArrayToFile(outputFilename1, resultArray, rows, cols);
    writeMinValuesToFile(outputFilename2, minValues, cols);
    
    std::cout << "\nMin Values:\n";
    for (int j = 0; j < cols; ++j)
    {
        std::cout << "Min values " << j + 1 << ": " << minValues[j] << std::endl;
    }
    
    freeMemory(originalArray, rows);
    freeMemory(resultArray, rows);
    delete[] minValues;

    return 0;
}
