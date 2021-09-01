#include<iostream>

using namespace std;

int Hive(int);

int main()
{
	int room;
	try
	{
		cin >> room;
		if ((room < 1) || (room > (1000000000)))
			throw 0;
	}
	catch (int ext)
	{
		cout << "Err: invalid input" << endl;
		return -1;
	}
	cout << Hive(room) << endl;
	return 0;
}

int Hive(int num)
{
	int layer = 1, l_start = 1, l_end = 1;	// initially
	while(1)
	{
		if ((num >= l_start) && (num <= l_end))
			return layer;
		l_start = l_end + 1;
		l_end = l_end + 6 * (layer);
		layer++;
	}
}