#include<iostream>
#define NUM 5

int main()
{
	int sum = 0;
	for (int i = 0, in; i < NUM; i++)
	{
		std::cout << i + 1 << "��° ���� �Է�: ";
		std::cin >> in;
		sum += in;
	}
	std::cout << "�հ�: " << sum << std::endl;
	return 0;
}