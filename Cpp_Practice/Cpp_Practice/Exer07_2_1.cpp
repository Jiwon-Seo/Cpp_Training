#include<iostream>
using namespace std;

//template <typename T>

class Rectangle
{
private:
	//T n1, n2;
	int num1, num2;
public:
	Rectangle(int n1, int n2) :num1(n1), num2(n2)
	{	}
	void ShowAreaInfo()
	{
		cout << "¸éÀû" << num1 * num2 << endl;
	}
};

class Square : public Rectangle
{
private:

public:
	Square(int s) :Rectangle(s, s)
	{	}
	//void Show
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
};