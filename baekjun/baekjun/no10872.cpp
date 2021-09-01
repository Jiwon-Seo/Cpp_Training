#include<iostream>

using namespace std;

int fact_recur(int);

int main()
{
	try
	{
		int num, output;
		cin >> num;
		if (num < 0 || num>12)
			throw 0;
		output = fact_recur(num);
		cout << output << endl;
	}
	catch (int except)
	{
		cout << "Err: not valid number" << endl;
		return -1;
	}
	return 0;
}

int fact_recur(int n)
{
	if (n > 1)
	{
		return n * fact_recur(n-1);
	}
	else
	{
		return 1;
	}
}