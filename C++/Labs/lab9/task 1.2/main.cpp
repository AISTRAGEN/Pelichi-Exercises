#include <iostream>

class Fraction 
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) 
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    
    void simplify() 
    {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

public:
    
    Fraction(int num, int denom) : numerator(num), denominator(denom) 
    {
        simplify();
    }

    // Перевантаження оператора виведення
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) 
    {
        if (frac.denominator == 1 || frac.numerator == 0) {
            os << frac.numerator;
        } else {
            os << frac.numerator << "/" << frac.denominator;
        }
        return os;
    }

    Fraction operator+(const Fraction& other) const 
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const 
    {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
   
    Fraction operator*(const Fraction& other) const 
    {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const 
    {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    bool operator<(const Fraction& other) const 
    {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator<=(const Fraction& other) const 
    {
        return numerator * other.denominator <= other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const 
    {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool operator>=(const Fraction& other) const 
    {
        return numerator * other.denominator >= other.numerator * denominator;
    }
};

int main() 
{
   
    int num1, denom1, num2, denom2;
    std::cout << "Введіть перший дріб (чисельник знаменник): ";
    std::cin >> num1 >> denom1;
    std::cout << "Введіть другий дріб (чисельник знаменник): ";
    std::cin >> num2 >> denom2;

    Fraction frac1(num1, denom1);
    Fraction frac2(num2, denom2);

    std::cout << "Перший дріб: " << frac1 << std::endl;
    std::cout << "Другий дріб: " << frac2 << std::endl;
    std::cout << "Додавання: " << frac1 + frac2 << std::endl;
    std::cout << "Віднімання: " << frac1 - frac2 << std::endl;
    std::cout << "Множення: " << frac1 * frac2 << std::endl;
    std::cout << "Ділення: " << frac1 / frac2 << std::endl;

    std::cout << "Порівняння (frac1 < frac2): " << (frac1 < frac2) << std::endl;
    std::cout << "Порівняння (frac1 <= frac2): " << (frac1 <= frac2) << std::endl;
    std::cout << "Порівняння (frac1 > frac2): " << (frac1 > frac2) << std::endl;
    std::cout << "Порівняння (frac1 >= frac2): " << (frac1 >= frac2) << std::endl;

    return 0;
}



