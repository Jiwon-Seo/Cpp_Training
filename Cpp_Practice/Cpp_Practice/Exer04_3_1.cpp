#include<iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y)
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
	Circle(int x, int y, int rad): center(x, y)
	{
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
	Ring(int in_x, int in_y, int in_rad, int out_x, int out_y, int out_rad): inner(in_x, in_y, in_rad), outter(out_x, out_y, out_rad)
	{	}
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
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}