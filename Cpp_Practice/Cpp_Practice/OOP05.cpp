#include<iostream>
#include<cstring>

#define N_LEN 10

using namespace std;

#if 0
void Acc_Create();
void Acc_deposit();
void Acc_withdraw();
const void Acc_showinfo();
#endif

class Account
{
private:
	int id;
	char* name;
	int deposit;
public:
	Account(int accID, char* accName, int money) : id(accID), deposit(money)
	{
		name = new char[strlen(accName) + 1];
		strcpy(name, accName);
	}
	Account(Account& ref) : id(ref.id), deposit(ref.deposit)
	{
		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
	}
	int GetID() const { return id; }
	void Deposit(int money)
	{
		deposit += money;
	}
	int Withdraw(int money)
	{
		if (deposit < money)
			return 0;
		deposit -= money;
		return money;
	}
	void ShowAccInfo() const
	{
		cout << "����ID: " << id << endl;
		cout << "�� ��: " << name << endl;
		cout << "�� ��: " << deposit << endl;
	}
	~Account()
	{
		delete[] name;
	}
};
class AccountHandler
{
private:
	Account* AccArr[100];
	int AccNum;
public:
	AccountHandler() :AccNum(0)
	{	}
	~AccountHandler()
	{
		for (int i = 0; i < AccNum; i++)
			delete AccArr[i];
	}
	void Acc_Create()
	{
		char name[N_LEN];
		int id, dep;

		cout << "[���°���]" << endl;
		cout << "����ID: ";
		cin >> id;
		cout << "�� ��: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> dep;
		AccArr[AccNum] = new Account(id, name, dep);
		AccNum++;
		cout << endl;
	}
	void Acc_deposit()
	{
		int tar_id, dep;
		cout << "[��   ��]" << endl;
		cout << "����ID: ";
		cin >> tar_id;
		cout << "�Աݾ�: ";
		cin >> dep;
		for (int i = 0; i < AccNum; i++)
		{
			if ((AccArr[i]->GetID()) == tar_id)
			{
				AccArr[i]->Deposit(dep);
				cout << endl;
				return;
			}
		}
	}
	void Acc_withdraw()
	{
		int tar_id, wit;
		int arrnum = 0;
		cout << "[��   ��]" << endl;
		cout << "����ID: ";
		cin >> tar_id;
		cout << "��ݾ�: ";
		cin >> wit;
		for (int i = 0; i < AccNum; i++)
		{
			if (AccArr[i]->GetID() == tar_id)
			{
				if (AccArr[i]->Withdraw(wit) == 0)
				{
					cout << "�ܾ׺���" << endl;
					return;
				}
				cout << endl;
				return;
			}
		}
	}
	void Acc_showinfo()
	{
		for (int i = 0; i < AccNum; i++)
		{
			AccArr[i]->ShowAccInfo();
		}
	}
	const void PrintMenu()
	{
		cout << "-----Menu------" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "����: ";
	}
};

int main()
{
	AccountHandler bank;
	int sel;

	while (1)
	{

		int sel;
		bank.PrintMenu();
		cin >> sel;
		if (sel == 5)	break;
		cout << endl;
		switch (sel)
		{
		case 1:
			bank.Acc_Create();
			break;
		case 2:
			bank.Acc_deposit();
			break;
		case 3:
			bank.Acc_withdraw();
			break;
		case 4:
			bank.Acc_showinfo();
			break;
		case 5:
			return 0;
		}
		cout << endl;
	}

	return 0;
}
