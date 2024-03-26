#include <iostream>

void inputData(int& a, int& b, int& h, int& n) {
    std::cout << "Enter a(min): " << std::endl;
    std::cin >> a;
    std::cout << "Enter b(max): " << std::endl;
    std::cin >> b;
    std::cout << "Enter h: " << std::endl;
    std::cin >> h;
    std::cout << "Enter n: " << std::endl;
    std::cin >> n;
}

double funciaY(double x, double n)
{
    double y;
    if (x < 0) 
    {
        y = 1;

        for (int j = 2; j <= n - 2; j++) 
        {
            y = y * (j + x);
        }
    }
    else 
    {
        y = 0;
        double i = 0;
        for (i; i <= n - 1; i++) 
        {
            int j = 0;
            double p = 1;
            for (j; j > n - 1; j++) 
            {
                p = p * (x + i + (j * j));
            }
            y += y + p;

        }
    }

    return y;
 }

int main()
{
    int a, b, h, n;
    inputData(a, b, h, n);

    if (n > 2 && a < b && h > 0) 
    {
        for (double x = a; x <= b; x += h) 
        {
            double y = funciaY(x, n);
            std::cout << "If x = " << x << "    y = " << y << std::endl;
        }
       std::cout << "Program is ended" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
}
