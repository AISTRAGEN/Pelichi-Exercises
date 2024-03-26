#include <iostream>

int main()
{
	unsigned int k, m, n;
	std::cout << "Input value  k (k > 0)" << std::endl;
	std::cin >> k;
	std::cout << "Input n"  << std::endl;
	std::cin >> n;
	std::cout << "Input m" << std::endl;
	std::cin >> m;
	((n >= 0 && n < 32) && (m >= 0 && m < 32)) ? void(0) : (std::cout << "Wrong value\n", exit(0));

	unsigned int bn = (k >> (n - 1)) & 0x1;
	unsigned int bm = (k >> (m - 1)) & 0x1;
	unsigned int Temp = bn ^ bm;
	k = k ^ (Temp << (n - 1));
	k = k ^ (Temp << (m - 1));

	std::cout << "Your number with swaped bits:" << " " << k << "\n" << std::endl;

	return 0;
}
