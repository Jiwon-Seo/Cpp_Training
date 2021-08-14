#include<iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point center;
	int radius;
public:
	void Init(int x, int y, int rad)
	{
		center.Init(x, y);
		radius = rad;
	}
	void ShowCircleInfo() const
	{
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inner, outter;
public:
	void Init(int in_x, int in_y, int in_rad, int out_x, int out_y, int out_rad)
	{
		inner.Init(in_x, in_y, in_rad);
		outter.Init(out_x, out_y, out_rad);
	}
	void ShowRingInfo()
	{
		cout << "Inner Circle Info" << endl;
		inner.ShowCircleInfo();
		cout << "Outter Circle Info" << endl;
		outter.ShowCircleInfo();
	}
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}