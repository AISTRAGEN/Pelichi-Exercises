#include <iostream>

int y ( int x, int n) 
{
    if (n == 0)
    {
        return 1;
    }
    else  return (x + n) * y(x, n - 1);
}

int main()
{
    int x, n;
   std:: cout << "Input x" << std::endl;
    std::cin >> x;
    std::cout << "Input n" << std::endl;
    std::cin >> n;
    if (n < 0) 
    {
        std::cout << "n must be not -(integer)" << std::endl;
    }
    else 
    {
        int result = y(x, n);
        std::cout << "y = " << result << std::endl;
    }
    return 0;
    
}
