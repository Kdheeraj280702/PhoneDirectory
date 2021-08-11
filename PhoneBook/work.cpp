#include <bits/stdc++.h>
#include "contact.h"
#include "work.h"
using namespace std;
Work ::Work(string name , string number , string email, string job) : Contact(name , number , email)
{
		Job = job;
}
void Work:: display()
{
		Contact::display();
		cout << "		Job : " << Job << endl << endl;
}