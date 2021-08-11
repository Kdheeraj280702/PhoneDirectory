#pragma once
#include <bits/stdc++.h>
#include "contact.h"
#include "personal.h"
using namespace std;
class Personal : public Contact {
	string Job;
public :
	Personal(string , string , string, string);
	void display();
};