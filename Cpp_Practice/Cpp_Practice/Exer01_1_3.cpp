#include<iostream>

int main()
{
	while (1)
	{
		int num;
		std::cout << "ют╥б: ";
		std::cin >> num;
		for (int i = 1; i <= 9; i++)
		{
			std::cout << num << " x " << i << " = " << num * i << std::endl;
		}
	}
	return 0;
}