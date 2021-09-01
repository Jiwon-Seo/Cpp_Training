#include<iostream>
#define NUM 9

using namespace std;

int main()
{
	int n[NUM], max, maxi;
	for (int i = 0; i < NUM; i++)
		cin >> n[i];
	max = n[NUM], maxi = 0;
	for (int i = 0; i < NUM; i++)
	{
		if (n[i] > max)
		{
			max = n[i];
			maxi = i;
		}
	}
	cout << max << endl << maxi + 1 << endl;
	return 0;
}