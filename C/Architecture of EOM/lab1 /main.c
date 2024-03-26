#include "header.h"

int main()
{
double x, y, z;

    printf("Введіть значення x: ");
    scanf("%lf", &x);
    printf("Введіть значення y: ");
    scanf("%lf", &y);
    printf("Введіть значення z: ");
    scanf("%lf", &z);

    double result_A = function_A(x, y);
    printf("Результат функції A: %.6f\n", result_A);

    double result_B = function_B(x, z);
    printf("Результат функції B: %.6f\n", result_B);

    return 0;
}
