#include<iostream>

void SwapPointer(int*, int*);

int main()
{
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;
	SwapPointer(ptr1, ptr2);
	std::cout << *ptr1 << ' ' << *ptr2 << std::endl;
	return 0;
}

void SwapPointer(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}