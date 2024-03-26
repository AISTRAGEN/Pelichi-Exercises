#include <iostream>

int min(int a, int b) 
{
	static int min = INT_MAX;

	if (a < min) min = a;
	if (b < min) min = b;
	return min;
	

}

int max(int a, int b)
{
	static int max = INT_MIN;

	if (a > max) max = a;
	if (b > max ) max = b;
	return max;


}
int main() 
{
	int a, b;
	std::cout << "enter 2 integers" << std::endl;
	std::cin >> a >> b;
	std::cout << "Minimum:" << min(a, b) << std::endl;
	std::cout << "Maximum:" << max(a, b) << std::endl;
	while (a != 0 || b != 0) 
	{
		std::cout << "Enter the following two integers (or 0 to exit)";
		std::cin >> a >> b;
		std::cout << "Minimum:" << min(a, b) << std::endl;
		std::cout << "Maximum:" << max(a, b) << std::endl;


	}

	return 0;
}
