// try again
#include<iostream>
using namespace std;

enum COMP_POS
{
	CLERK=0, SENIOR, ASSIST, MANAGER
};

class NameCard
{
private:
	char* name;
	char* company;
	char* phone_num;
	int position;
public:
	NameCard(char* name, char* company, char* phone_num, int pos) :position(pos)
	{
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone_num = new char[strlen(phone_num) + 1];
		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phone_num, phone_num);
	}
	NameCard(const NameCard& ref) :position(ref.position)
	{
		name = new char[strlen(ref.name) + 1];
		company = new char[strlen(ref.company) + 1];
		phone_num = new char[strlen(ref.phone_num) + 1];
		strcpy(name, ref.name);
		strcpy(company, ref.company);
		strcpy(phone_num, ref.phone_num);
	}
	void ShowNameCardInfo()
	{
		cout << "name    : " << name << endl;
		cout << "company : " << company << endl;
		cout << "phone   : " << phone_num << endl;
		cout << "position: ";
		ShowPosition();
		cout << endl;
	}
	void ShowPosition()
	{
		switch (position)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
		}
	}
	~NameCard()
	{
		delete[] name;
		delete[] company;
		delete[] phone_num;
	}
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;

	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}