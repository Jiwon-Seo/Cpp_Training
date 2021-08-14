#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cout << rand() % 100 << endl;
	}
	cout << endl;
	srand(100);
	for (int i = 0; i < 5; i++)
	{
		cout << rand() % 100 << endl;
	}
	cout << endl;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		cout << rand() % 100 << endl;
	}
	return 0;
}