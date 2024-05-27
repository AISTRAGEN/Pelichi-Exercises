#include <iostream>
#include <stdexcept>

template<typename T>
class Matrix 
{
private:
    T** data;
    int rows;
    int cols;

public:
    
    Matrix() : data(nullptr), rows(0), cols(0) {}

    
    Matrix(int rows, int cols) : rows(rows), cols(cols) 
    {
        if (rows <= 0 || cols <= 0) 
        {
            throw std::invalid_argument("Розміри матриці повинні бути більшими за 0");
        }
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) 
        {
            data[i] = new T[cols];
        }
    }

    
    ~Matrix() 
    {
        for (int i = 0; i < rows; ++i) 
        {
            delete[] data[i];
        }
        delete[] data;
    }

   
    Matrix operator+(const Matrix& other) const 
    {
        if (rows != other.rows || cols != other.cols) 
        {
            throw std::invalid_argument("Розміри матриць повинні бути однаковими для додавання");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    
    Matrix operator-(const Matrix& other) const 
    {
        if (rows != other.rows || cols != other.cols) 
        {
            throw std::invalid_argument("Розміри матриць повинні бути однаковими для віднімання");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    
    Matrix operator*(T scalar) const 
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    
    T* operator[](int index) const 
    {
        if (index < 0 || index >= rows) 
        {
            throw std::out_of_range("Індекс рядка за межами дійсного діапазону");
        }
        return data[index];
    }

    
    friend std::istream& operator>>(std::istream& is, Matrix& matrix) 
    {
        for (int i = 0; i < matrix.rows; ++i) 
        {
            for (int j = 0; j < matrix.cols; ++j) 
            {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

   
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) 
    {
        for (int i = 0; i < matrix.rows; ++i) 
        {
            for (int j = 0; j < matrix.cols; ++j) 
            {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    
    Matrix operator!() const 
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                result.data[i][j] = abs(data[i][j]);
            }
        }
        return result;
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

        

    } catch (const std::invalid_argument& e) 
    {
        std::cerr << "Помилка: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) 
    {
        std::cerr << "Помилка: " << e.what() << std::endl;
    } catch (...) 
    {
        std::cerr << "Невідома помилка." << std::endl;
    }

    return 0;
}
