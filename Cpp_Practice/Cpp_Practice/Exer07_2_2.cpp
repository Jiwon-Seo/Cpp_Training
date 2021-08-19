#include<iostream>

using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* t, char* i, int p) :price(p)
	{
		title = new char[strlen(t) + 1];
		isbn = new char[strlen(i) + 1];
		strcpy(title, t);
		strcpy(isbn, i);
	}
	void ShowBookInfo()
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class Ebook :Book
{
private:
	char* DRMKey;
public:
	Ebook(char* t, char* i, int p, char* D) :Book(t, i, p)
	{
		DRMKey = new char[strlen(D) + 1];
		strcpy(DRMKey, D);
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
	~Ebook()
	{
		delete[] DRMKey;
	}
};

int main()
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	Ebook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}