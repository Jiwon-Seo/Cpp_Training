#include<iostream>
#include<cstring>

using namespace std;
int main()
{
	char name[100] = "asdf asd fas df";
	char copy[50];
	cout << strlen(name) << endl;
	cout << strcat(name, "qwer") << endl;
	cout << strcpy(copy, name) << endl;
	cout << strcmp(copy, name) << endl;
	return 0;
}