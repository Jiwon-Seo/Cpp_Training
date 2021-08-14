#include<iostream>
using namespace std;

enum COMP_POS
{
	CLERK = 0, SENIOR, ASSIST, MANAGER
};

class NameCard
{
private:
	char* name;
	char* company;
	char* phone_num;
	int position;
public:
	NameCard(char* n, char* comp, char* ph, int pos) :name(n), company(comp), phone_num(ph), position(pos)
	{}
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
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}