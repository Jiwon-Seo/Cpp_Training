#include<iostream>
using namespace std;
class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(char* n, int a) :age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	void ShowMyFriendInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~MyFriendInfo()
	{
		delete[] name;
	}
};

class MyFriendDetailInfo :public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(char* a, char* ph, char* n, int age) :MyFriendInfo(n, age)
	{
		addr = new char[strlen(a) + 1];
		phone = new char[strlen(ph) + 1];
		strcpy(addr, a);
		strcpy(phone, ph);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl << endl;
	}
	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
	}
};