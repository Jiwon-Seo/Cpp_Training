#include<iostream>

using namespace std;

int main()
{
	int num, min, max;
	int* data = new int[1000000];
	try
	{
		cin >> num;
		if ((num < 1) || (num > 1000000))
			throw 0;
	}
	catch(int except)
	{
		cout << "Err: invalid number" << endl;
		//return -1;
	}
	for (int i = 0; i < num; i++)
		cin >> data[i];
	min = data[0], max = data[0];
	for (int i = 1; i < num; i++)
	{
		if (min > data[i])
			min = data[i];
		if (max < data[i])
			max = data[i];
	}
	cout << min << ' ' << max << endl;
	delete[] data;
	return 0;
}