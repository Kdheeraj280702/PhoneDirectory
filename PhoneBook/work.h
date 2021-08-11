#pragma once
#include <bits/stdc++.h>
#include "contact.h"
using namespace std;
class Work : public Contact {
	string Job;
public :
	Work(string name , string number , string email, string job);
	void display();
};