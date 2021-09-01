#include<iostream>

using namespace std;

void breakpoint(int a, int b, int c);

int main()
{
	int a;
	int b, c;
	cin >> a >> b >> c;
	breakpoint(a, b, c);

	return 0;
}

void breakpoint(int a, int b, int c)
{
	int i = 0;
	if (b >= c)
	{
		cout << -1 << endl;
		return;
	}
	i = ((-a) / (b - c))+1;
#if 0
	while (1)
	{
		i++;
		if ((a + b * i) - (c * i) < 0)
			break;
	}
#endif
	cout << i << endl;
}