#include<iostream>

using namespace std;

int Fibonacci_recur(int);

int main()
{
	try
	{
		int N;
		int res;
		cin >> N;
		if (N < 0 || N > 20)
			throw 0;
		res = Fibonacci_recur(N);
		cout << res << endl;
	}
	catch (int ext)
	{
		cout << "Err: not valid number!" << endl;
	}
	return 0;
}

int Fibonacci_recur(int N)
{
	if (N == 1)
		return 1;
	else if (N == 0)
		return 0;
	else
		return Fibonacci_recur(N - 2) + Fibonacci_recur(N - 1);
}