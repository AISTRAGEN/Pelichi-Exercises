#include <iostream>

int func(int x = 0, int y = 0, int z = 0) 
{
    if (x == 0 && y == 0 && z == 0) 
    {
        return 1;
    }
    else if (y == 0 && z == 0) 
    {
        return x;
    }
    else 
    {
        return x * y * z;
    }
}

int funcOverloaded(int x) 
{
    return x;
}

int funcOverloaded(int x, int y) 
{
    return x * y;
}

int funcOverloaded(int x, int y, int z) 
{ 
    return x * y * z;
}

int main() 
{
    std::cout << "Func() = " << func() << std::endl; 
    std::cout << "Func(2) = " << func(2) << std::endl; 
    std::cout << "Func(2, 3) = " << func(2, 3) << std::endl; 
    std::cout << "Func(2, 3, 4) = " << func(2, 3, 4) << std::endl;
    std::cout << "FuncOverloaded(2) = " << funcOverloaded(2) << std::endl;
    std::cout << "FuncOverloaded(2, 3) = " << funcOverloaded(2, 3) << std::endl; 
   std:: cout << "FuncOverloaded(2, 3, 4) " << funcOverloaded(2, 3, 4) << std::endl;

    return 0;
}
   