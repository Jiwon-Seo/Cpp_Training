#include<iostream>

int main()
{
	char name[20], tel[20];
	std::cout << "이름 : ";
	std::cin >> name;
	std::cout << "전화번호 : ";
	std::cin >> tel;
	std::cout << "이름 : " << name << "  전화번호 : " << tel << std::endl;
	
	return 0;
}