#include<iostream>
using namespace std;

void add(int&);
void rev(int&);

int main()
{
	int num = 10;
	add(num);
	cout << num << endl;
	rev(num);
	cout << num << endl;
	return 0;
}

void add(int& num)
{
	num++;
}
void rev(int& num)
{
	num *= -1;
}