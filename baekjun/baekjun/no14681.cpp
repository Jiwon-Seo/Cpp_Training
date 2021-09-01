#include<iostream>

using namespace std;

enum Q
{
	QUAD1 = 1, QUAD2, QUAD3, QUAD4
};

int main()
{
	int x, y;
	try
	{
		cin >> x >> y;
		if ((x < -1000) || (x > 1000) || (x == 0) || (y < -1000) || (y > 1000) || (y == 0))
			throw 0;
	}
	catch(int excpt)
	{
		cout << "Err: not valid number!!" << endl;
	}

	if (x > 0)
	{
		if (y > 0)
			cout << QUAD1 << endl;
		else
			cout << QUAD4 << endl;
	}
	else
	{
		if (y > 0)
			cout << QUAD2 << endl;
		else
			cout << QUAD3 << endl;
	}
	return 0;
}