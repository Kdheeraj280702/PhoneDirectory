
#pragma once
#include <bits/stdc++.h>
#include "Contact.h"
#include "Trie.h"
class PhoneBook {
	Trie* names;
	Trie* numbers;
	Trie* email;
	map<string , vector<Contact*>> NAMES;
	map<string , vector<Contact*>> NUMBERS;
	map<string , vector<Contact*>> EMAILS;
	vector<string> searchResults;
public :
	PhoneBook();
	void print(int i);
	void insert(Contact* contact);

	void search(string,int);
	void store();
	void read_from_file();
	
};
