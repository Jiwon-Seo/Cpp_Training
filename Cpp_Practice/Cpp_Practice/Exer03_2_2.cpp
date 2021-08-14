#include<iostream>

using namespace std;

class Printer
{
private:
	char* ptrstr;
public:
	void SetString(char*);
	void ShowString();
};

int main()
{
	Printer pnt;
	pnt.SetString("Hello world!!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}

void Printer::SetString(char* get_str)
{
	ptrstr = get_str;
}

void Printer::ShowString()
{
	cout << ptrstr << endl;
}