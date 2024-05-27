#include "function.h"
#include "header.h"

class MyFunctionSolver : public FunctionSolver 
{
public:
    double solve() override 
    {
        int a, b, h;
        inputData(a, b, h); // Виклик функції зчитування даних з користувача
        return findDerivative(a, b, h); // Виклик функції обчислення похідної
    }

    double findDerivative(int a, int b, int h) override 
    {
        // Ваш код для обчислення похідної
        for (int x = a; x < b; x += h) {
            double deltaX = 0.0000001;
            double y_x = 3 * (-x * x * x) + 1;
            double y_x_plus_delta = 3 * (-(x + deltaX) * (x + deltaX) * (x + deltaX)) + 1;
            double derivative = (y_x_plus_delta - y_x) / deltaX;

            if (derivative == 0.0) {
                return x;
            }
        }
        return -1; // Повертаємо -1 у випадку, якщо похідна не знайдена
    }
};
