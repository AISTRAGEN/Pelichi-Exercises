#include <iostream>
#include <stdexcept>
class Matrix 
{
private:
    int** data;
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
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) 
        {
            data[i] = new int[cols];
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

    
    Matrix operator*(int scalar) const 
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

    int* operator[](int index) const 
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


int main() 
{
    try 
    {
        
        Matrix matrix1(3, 3);

       
        std::cout << "Введіть елементи матриці 3x3:" << std::endl;
        std::cin >> matrix1;

       
        std::cout << "Матриця 1:" << std::endl;
        std::cout << matrix1;

        
        std::cout << "Елемент матриці 1 з рядка 1 і стовпця 2: " << matrix1[1][2] << std::endl;

       
        Matrix absMatrix = !matrix1;
        std::cout << "Матриця абсолютних значень:" << std::endl;
        std::cout << absMatrix;

        Matrix validMatrix(2, 2);

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
