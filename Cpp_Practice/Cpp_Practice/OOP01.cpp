#include<iostream>
#include<cstring>
using namespace std;

typedef struct ACCOUNT
{
	int id;
	char name[10];
	int deposit;

} Acc;

void Acc_Create();
void Acc_deposit();
void Acc_withdraw();
void Acc_showinfo();
void PrintMenu();
void Selection(int);

Acc AccArr[100];
int AccNum = 0;

int main()
{
	while (1)
	{
		int sel;
		PrintMenu();
		cin >> sel;
		if (sel == 5)	break;
		cout << endl;
		Selection(sel);
		cout << endl;
	}
	return 0;
}

void Acc_Create()
{
	char name[10];
	int id, dep;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> dep;
	AccArr[AccNum].id = id;
	strcpy(AccArr[AccNum].name, name);
	AccArr[AccNum].deposit = dep;
	AccNum++;
	cout << endl;
}
void Acc_deposit()
{
	int tar_id, dep;
	int arrnum = 0;
	cout << "[입   금]" << endl;
	cout << "계좌ID: ";
	cin >> tar_id;
	cout << "입금액: " ;
	cin >> dep;
	while (1)
	{
		if (tar_id == AccArr[arrnum].id)	break;
		arrnum++;
	}
	AccArr[arrnum].deposit += dep;
	cout << endl;
}
void Acc_withdraw()
{
	int tar_id, wit;
	int arrnum = 0;
	cout << "[출   금]" << endl;
	cout << "계좌ID: ";
	cin >> tar_id;
	cout << "출금액: " ;
	cin >> wit;
	while (1)
	{
		if (tar_id == AccArr[arrnum].id)	break;
		arrnum++;
	}
	AccArr[arrnum].deposit -= wit;
	cout << endl;
}
void Acc_showinfo()
{
	for (int i = 0; i < AccNum; i++)
	{
		cout << "계좌ID: " << AccArr[i].id << endl;
		cout << "이 름: " << AccArr[i].name << endl;
		cout << "잔 액: " << AccArr[i].deposit << endl;
	}
	cout << endl;
}
void PrintMenu()
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}
void Selection(int num)
{
	switch (num)
	{
	case 1:
		Acc_Create();
		break;
	case 2:
		Acc_deposit();
		break;
	case 3:
		Acc_withdraw();
		break;
	case 4:
		Acc_showinfo();
		break;
	}
}
