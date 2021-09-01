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

enum GRADE
{
	A = 7, B = 4, C = 2
};

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
	virtual void Deposit(int money)
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
		cout << "계좌ID: " << id << endl;
		cout << "이 름: " << name << endl;
		cout << "잔 액: " << deposit << endl;
	}
	~Account()
	{
		delete[] name;
	}
};
class NormalAccount :public Account
{
private:
	int rate;
public:
	NormalAccount(int id, char* name, int money, int interest) : Account(id, name, money), rate(interest)
	{	}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (rate) / 100.0);
	}
};
class HighCreditAccount :public NormalAccount
{
private:
	int grade;
public:
	HighCreditAccount(int id, char* name, int money, int interest, int gr) :NormalAccount(id, name, money, interest), grade(gr)
	{	}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money * (grade) / 100.0);
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
		int accsel;
		PrintMenuAccSel();
		cin >> accsel;
		if (accsel == 1)
			Acc_Create_Normal();
		else
			Acc_Create_Credit();
#if 0
		cout << "[계좌개설]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> dep;
		AccArr[AccNum] = new Account(id, name, dep);
		AccNum++;
		cout << endl;
#endif
	}
	void Acc_deposit()
	{
		int tar_id, dep;
		cout << "[입   금]" << endl;
		cout << "계좌ID: ";
		cin >> tar_id;
		cout << "입금액: ";
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
		cout << "[출   금]" << endl;
		cout << "계좌ID: ";
		cin >> tar_id;
		cout << "출금액: ";
		cin >> wit;
		for (int i = 0; i < AccNum; i++)
		{
			if (AccArr[i]->GetID() == tar_id)
			{
				if (AccArr[i]->Withdraw(wit) == 0)
				{
					cout << "잔액부족" << endl;
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
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: ";
	}
	const void PrintMenuAccSel()
	{
		cout << "[계좌종류선택]" << endl;
		cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
		cout << "선택: ";
	}
protected:
	void Acc_Create_Normal()
	{
		int id;
		char name[N_LEN];
		int dep, rate;

		cout << "[보통예금계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> dep;
		cout << "이자율: ";
		cin >> rate;
		AccArr[AccNum] = new NormalAccount(id, name, dep, rate);
		AccNum++;
		cout << endl;
	}
	void Acc_Create_Credit()
	{
		int id;
		char name[N_LEN];
		int dep, rate, grade;

		cout << "[신용신뢰계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> id;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> dep;
		cout << "이자율: ";
		cin >> rate;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> grade;
		switch (grade)
		{
		case 1:
			AccArr[AccNum] = new HighCreditAccount(id, name, dep, rate, GRADE::A);
			break;
		case 2:
			AccArr[AccNum] = new HighCreditAccount(id, name, dep, rate, GRADE::B);
			break;
		case 3:
			AccArr[AccNum] = new HighCreditAccount(id, name, dep, rate, GRADE::C);
			break;
		default:
			cout << "Err: invalid grade selection" << endl;
			return;
		}
		AccNum++;
		cout << endl;
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
