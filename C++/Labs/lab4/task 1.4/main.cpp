#include <iostream>
#include <cmath>

int solveSquare(double a, double b, double c, double& x1, double& x2) 
{

    auto SolveDiscriminant = [&a, &b, &c]() 
    {
        return b * b - 4 * a * c;
    };

    double d = SolveDiscriminant();

    if (a != 0) 
    {
        if (d > 0) 
        {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);

            return 2;
        }
        else if (d == 0) 
        {
            x1 = -b / (2 * a);

            return 1;
        }
        else 
        {
            return 0;
        }
    }
    else 
    {
        if (b != 0) 
        {
            x1 = x2 = -c / b;
            return 1;
        }
        else
        {
            if (c == 0) 
            {
                return -1;
            }
            else 
            {
                return 0;
            }
        }
    }
}

int main() 
{ 
    double a, b, c;
    std::cout << "Input value  a, b and c: ";
    std::cin >> a >> b >> c;
    double root1, root2;
    int numberOfRoots = solveSquare(a, b, c, root1, root2);
    if (numberOfRoots == 2) 
    {
        std::cout << "equation have 2 roots:" << root1 << " and " << root2 << std::endl;
    }
    else if (numberOfRoots == 1) 
    {
        std::cout << "equation have 1 root: " << root1 << std::endl;
    }
    else if (numberOfRoots == 0) 
    {
        std::cout << "equation don't have roots" << std::endl;
    }
    else if (numberOfRoots == -1) 
    {
        std::cout << "multiple outcomes" << std::endl;
    }

    return 0;
}
