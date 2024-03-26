#include <iostream>
#include <string>

void hello ()
{
    std::string name;
    std::cout << "Enter the name" << std::endl;
    std::cin >> name;
    std::cout << "Hello" << " " << name << " " << "World" << "!" << std::endl;

}

int main()
{
   hello();
}
