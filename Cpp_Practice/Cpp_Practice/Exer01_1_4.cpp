#include<iostream>

int main()
{
	int in = 0;
	while (1)
	{
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է� (-1 to end) : ";
		std::cin >> in;
		if (in == -1)	break;
		std::cout << "�̹� �� �޿�: " << in * .12 + 50 << "����" << std::endl;
	}
	std::cout << "���α׷��� �����մϴ�." << std::endl;
	return 0;
}