#include<iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main()
{
	Point* pnt1 = new Point;
	Point& ref_p1 = *pnt1;
	Point* pnt2 = new Point;
	Point& ref_p2 = *pnt2;

	ref_p1.xpos = 1;
	ref_p1.ypos = 2;
	ref_p2.xpos = 3;
	ref_p2.ypos = 4;

	Point &res = PntAdder(ref_p1, ref_p2);	//

	cout << res.xpos << ' ' << res.ypos << endl;

	delete pnt1;
	delete pnt2;
	delete& res;	//
	return 0;
}

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* p_ret = new Point;	//
	p_ret->xpos = p1.xpos + p2.xpos;	//
	p_ret->ypos = p1.ypos + p2.ypos;	//
	return *p_ret;	//
}