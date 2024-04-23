#include "header.h"

using namespace mySpace;

void inputData(double &a, double &b)
{
   std::cout << "Ввведіть значення а" << std::endl;
   std::cin >> a;
   std::cout << "Введіть значення b" << std::endl;
   std::cin >> b;
}

void outputData(double &a, double &b,  functionPtr function)
{
    std::cout << "Сума а i b = " << function(a,b) << std::endl;
}

double funcion(double a, double b)
{
  double result = pow(a, 2) + pow (b, 2);
  return result;
}

int main()
{
    double a, b;
    inputData(a, b);
    outputData(a, b, funcion);
    functionPtr functions[] = {&pow, &hypot, &fmax, &fmin, &funcion};

   for (int i = 0; i < static_cast<int>(sizeof(functions) / sizeof(functions[0])); ++i)
    {
        print(a, b, functions[i]);
    }

    return 0;
}

