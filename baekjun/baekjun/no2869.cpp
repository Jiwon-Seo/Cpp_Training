// try again

#include<iostream>

using namespace std;

int main()
{
	int A, B, V, i;

	try
	{
		cin >> A >> B >> V;
		if ((B >= A) || (A > V) || (V > 1000000000) || (B < 1))
			throw 0;
	}
	catch (int ext)
	{
		cout << "Err: invalid input" << endl;
		exit(-1);
	}

	i = (V - B - 1) / (A - B) + 1;

	cout << i << endl;
	return 0;
}