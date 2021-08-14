#include<iostream>
#define NUM 5

int main()
{
	int sum = 0;
	for (int i = 0, in; i < NUM; i++)
	{
		std::cout << i + 1 << "번째 정수 입력: ";
		std::cin >> in;
		sum += in;
	}
	std::cout << "합계: " << sum << std::endl;
	return 0;
}