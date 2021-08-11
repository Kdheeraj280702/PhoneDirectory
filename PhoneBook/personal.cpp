#include <bits/stdc++.h>
#include "contact.h"
#include "personal.h"
using namespace std;
Personal :: Personal(string name , string number , string email, string birthday) : Contact(name , number , email)
	{
		Birthday = birthday;
	}
 void Personal:: display()
{
		Contact::display();
		cout << "		Birthday : " << Birthday << endl << endl;
}