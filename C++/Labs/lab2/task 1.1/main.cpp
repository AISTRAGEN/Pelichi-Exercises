#include <iostream>

int main()
{
	int number;
	std::cout << "Number 33 to 255\n" << " ";
	std::cin >> number;
	std::cout << (number >= 33 && number <= 255 ? "On ASCII table its" : "enter a number in the range from 33 to 255");
	std::cout << " " << char(number);

	return 0;
}

