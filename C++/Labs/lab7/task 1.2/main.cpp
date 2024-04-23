#include "header.h"

void inputData(int &a, int &b,int &h)
{
std::cout << "Ввведіть значення a(min)" << std::endl;
std::cin >> a;
std::cout << "Ввведіть значення b(max)" << std::endl;
std::cin >> b;
std::cout << "Ввведіть значення h" << std::endl;
std::cin >> h;
}

int main()
{
    int a, b, h;
    inputData(a, b, h);
    double result = outputData(findDerivative, a, b, h);
    std::cout << "Result is: " << result << std::endl;
    return 0;
}
