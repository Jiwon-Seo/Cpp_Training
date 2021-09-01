// try again

#include<iostream>
#define DENOMINATOR 42
#define NUM 10
using namespace std;

int Remain_Diff(int*);

int main()
{
	int A[10] = { 0 };
	for (int i = 0; i < NUM; i++)
		cin >> A[i];

	cout << Remain_Diff(A) << endl;
	return 0;
}

int Remain_Diff(int *A)
{
	int dist = 0;

	for (int i = 0; i < NUM; i++)
	{
		A[i] %= DENOMINATOR;
		//cout << A[i] << endl;
	}
	for (int i = 0; i < NUM; i++)
	{
		int comp = 0;
		for (int j = i + 1; j < NUM; j++)
		{
			if (A[i] == A[j])
			{
				comp++;
				break;
			}
		}
		if (comp == 0)
			dist++;
	}
	return dist;
}