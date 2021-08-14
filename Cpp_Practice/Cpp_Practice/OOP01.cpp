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

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
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
	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> tar_id;
	cout << "�Աݾ�: " ;
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
	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> tar_id;
	cout << "��ݾ�: " ;
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
		cout << "����ID: " << AccArr[i].id << endl;
		cout << "�� ��: " << AccArr[i].name << endl;
		cout << "�� ��: " << AccArr[i].deposit << endl;
	}
	cout << endl;
}
void PrintMenu()
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
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
