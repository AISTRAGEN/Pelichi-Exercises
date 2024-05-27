#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
class Matrix 
{
private:
    std::vector<std::vector<T>> data;

public:
    Matrix() : data() {}

    Matrix(int rows, int cols) : data(rows, std::vector<T>(cols)) 
    {
        if (rows <= 0 || cols <= 0) 
        {
            throw std::invalid_argument("Розміри матриці повинні бути більшими за 0");
        }
    }

    Matrix operator+(const Matrix& other) const 
    {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) 
        {
            throw std::invalid_argument("Розміри матриць повинні бути однаковими для додавання");
        }
        Matrix result(data.size(), data[0].size());
        for (int i = 0; i < data.size(); ++i) 
        {
            for (int j = 0; j < data[0].size(); ++j) 
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    std::vector<T>& operator[](int index) 
    {
        if (index < 0 || index >= data.size()) 
        {
            throw std::out_of_range("Індекс рядка за межами дійсного діапазону");
        }
        return data[index];
    }

    const std::vector<T>& operator[](int index) const 
    {
        if (index < 0 || index >= data.size()) 
        {
            throw std::out_of_range("Індекс рядка за межами дійсного діапазону");
        }
        return data[index];
    }

   
    template<typename U>
    friend U findMin(const U* arr, int size);

    // Функції введення та виведення матриці.
    friend std::istream& operator>>(std::istream& is, Matrix& matrix) 
    {
        for (int i = 0; i < matrix.data.size(); ++i) 
        {
            for (int j = 0; j < matrix.data[0].size(); ++j) 
            {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) 
    {
        for (int i = 0; i < matrix.data.size(); ++i) 
        {
            for (int j = 0; j < matrix.data[0].size(); ++j) 
            {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};


template<typename T>
T findMin(const T* arr, int size)
{
    if (size <= 0)
    {
        throw std::invalid_argument("Розмір масиву повинен бути більшим за 0");
    }
    T min = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main() 
{
    try 
    {
        Matrix<int> intMatrix(3, 3);

        std::cout << "Введіть елементи матриці 3x3 для цілих чисел:" << std::endl;
        std::cin >> intMatrix;

        std::cout << "Матриця цілих чисел:" << std::endl;
        std::cout << intMatrix;

        int intArray[] = {1, 3, 2, 5, 4};
        int intMin = findMin(intArray, 5);
        std::cout << "Мінімальний елемент у масиві цілих чисел: " << intMin << std::endl;

        Matrix<double> doubleMatrix(3, 3);

        std::cout << "Введіть елементи матриці 3x3 для дійсних чисел:" << std::endl;
        std::cin >> doubleMatrix;

        std::cout << "Матриця дійсних чисел:" << std::endl;
        std::cout << doubleMatrix;

        double doubleArray[] = {1.1, 3.3, 2.2, 5.5, 4.4};
        double doubleMin = findMin(doubleArray, 5);
        std::cout << "Мінімальний елемент у масиві дійсних чисел: " << doubleMin << std::endl;
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Помилка: " << e.what() << std::endl;
    } 
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Помилка: " << e.what() << std::endl;
    } 
    catch (...) 
    {
        std::cerr << "Невідома помилка." << std::endl;
    }

    return 0;
}
