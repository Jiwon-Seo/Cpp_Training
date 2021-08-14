#include<iostream>

using namespace std;

class Calculator
{
private:
	double num1;
	double num2;
	double cnt_add, cnt_min, cnt_mul, cnt_div;
public:
	void Init();
	double Add(double n1, double n2);
	double Div(double n1, double n2);
	double Min(double n1, double n2);
	double Mul(double n1, double n2);
	void ShowOpCount();
};

int main()
{
	Calculator cal;
	cal.Init();
	cout << cal.Add(3.2, 2.4) << endl;
	cout << cal.Div(3.5, 1.7) << endl;
	cout << cal.Min(2.2, 1.5) << endl;
	cout << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}

void Calculator::Init()
{
	cnt_add = 0.;
	cnt_min = 0.;
	cnt_mul = 0.;
	cnt_div = 0.;
}

double Calculator::Add(double n1, double n2)
{
	cnt_add++;
	return n1 + n2;
}
double Calculator::Div(double n1, double n2)
{
	if (n2 != 0)
	{
		cnt_div++;
		return n1 / n2;
	}
	else
	{
		cout << "Denominator is 0!!" << endl;
		return 0;
	}
}
double Calculator::Mul(double n1, double n2)
{
	cnt_mul++;
	return n1 * n2;
}
double Calculator::Min(double n1, double n2)
{
	cnt_min++;
	return n1 - n2;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << cnt_add << ' ';
	cout << "»¬¼À: " << cnt_min << ' ';
	cout << "°ö¼À: " << cnt_mul << ' ';
	cout << "³ª´°¼À: " << cnt_div << endl;
}