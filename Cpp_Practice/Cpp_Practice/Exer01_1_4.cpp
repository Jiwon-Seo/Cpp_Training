#include<iostream>

int main()
{
	int in = 0;
	while (1)
	{
		std::cout << "판매 금액을 만원 단위로 입력 (-1 to end) : ";
		std::cin >> in;
		if (in == -1)	break;
		std::cout << "이번 달 급여: " << in * .12 + 50 << "만원" << std::endl;
	}
	std::cout << "프로그램을 종료합니다." << std::endl;
	return 0;
}