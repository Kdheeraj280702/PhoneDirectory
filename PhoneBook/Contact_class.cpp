#include <bits/stdc++.h>
using namespace std;
class Contact {
public:
	string Name;
	string Number;
	string Email;
	Contact(string name, string number , string email)
	{
		Number = number;
		Name = name;
		Email = email;
	}
	virtual void display()
	{
		cout << "		Name : " << Name << endl;
		cout << "		Number : " << Number << endl;
		cout << "		Email : " << Email << endl;
	}
};

class Personal : public Contact {
	string Birthday;
public :
	Personal(string name , string number , string email, string birthday) : Contact(name , number , email)
	{
		Birthday = birthday;
	}
	void display()
	{
		Contact::display();
		cout << "		Birthday : " << Birthday << endl << endl;
	}
};
class Work : public Contact {
	string Job;
public :
	Work(string name , string number , string email, string job) : Contact(name , number , email)
	{
		Job = job;
	}
	void display()
	{
		Contact::display();
		cout << "		Job : " << Job << endl << endl;
	}
};
