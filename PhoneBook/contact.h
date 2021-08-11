#pragma once
#include <bits/stdc++.h>
using namespace std;
class Contact {
public:
	string Name;
	string Number;
	string Email;
	Contact(string, string, string);
	virtual void display()
	{
		cout << "		Name : " << Name << endl;
		cout << "		Number : " << Number << endl;
		cout << "		Email : " << Email << endl;
	}
};