#include <iostream>

int main()
{
    double a, b, h;
    int n;
    std::cout << "Enter a(min): " << std::endl;
    std::cin >> a;
    std::cout << "Enter b(max): " << std::endl;
    std::cin >> b;
    std::cout << "Enter h: " << std::endl;
    std::cin >> h;
    std::cout << "Enter n: " << std::endl;
    std::cin >> n;
    if (n < 2) 
    {
        std::cout << "Wrong data" << std::endl;
    }
    else  
    {
        for (double x = a; x <= b; x += h) 
        {
            if (x > b) 
            {
                return 0;
            }
            else 
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
                std::cout << "X value:" << x << std::endl;
                std::cout << "Y value:" << y << std::endl;
            }
            
        }
    }
}
