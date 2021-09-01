#include<iostream>

using namespace std;

int main()
{
	int A, B;
	double result;
	try
	{
		cin >> A >> B;
		if ((A < 0) || (B > 10))	throw B;
		else	result = (double)A / (double)B;
	}
	catch (int expn)
	{
		cout << "Err" << endl;
	}
	cout.precision(9);
	cout << fixed << result << endl;
	return 0;
}