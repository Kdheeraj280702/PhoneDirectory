#include <bits/stdc++.h>
#include "Contact_class.cpp"
#include "Dict.cpp"

using namespace std;
ofstream Contacts_file;

void Prompt()
{
	cout << "------------WELCOME TO PHONE DIRECTORY----------" << endl << endl;
	cout << "--------------HOW CAN I ASSIST YOU------------" << endl << endl;
	cout << "1. SAVE A NUMBER" << endl;
	cout << "2. SEARCH A CONTACT" << endl;
	cout << "3. EXIT" << endl;
	cout << "Enter your query type : ";
}
class PhoneBook {
public :
	Trie* names;
	Trie* numbers;
	Trie* email;
	map<string , vector<Contact*>> NAMES;
	map<string , vector<Contact*>> NUMBERS;
	map<string , vector<Contact*>> EMAILS;
	vector<string> searchResults;
	PhoneBook()
	{
		names = new Trie();
		email = new Trie();
		numbers = new Trie();
	}
	void print(int i)
	{

		switch (i)
		{
		case 1 : for (auto j : searchResults) for (auto result : NAMES[j]) result->display();
			break;
		case 2 :  for (auto j : searchResults) for (auto result : NUMBERS[j]) result->display();
			break;
		case 3 : for (auto j : searchResults) for (auto result : EMAILS[j]) result->display();
			break;
		}
		searchResults.clear();
	}


	void insert(Contact* contact)
	{

		NAMES[contact->Name].push_back(contact);

		EMAILS[contact->Email].push_back(contact);

		NUMBERS[contact->Number].push_back(contact);

		names->insert(contact->Name);

		numbers->insert(contact->Number);

		email->insert(contact->Email);


	}

	void search(string prefix , int i)
	{

		bool ans = 0;
		switch (i)
		{
		case 1 : ans = names->search(prefix , searchResults);

			break;
		case 2 :  ans = numbers->search(prefix , searchResults);
			break;
		case 3 :  ans = email->search(prefix , searchResults);
			break;
		default : cout << "Not a Valid request ";
			break;
		}
		if (ans) print(i);
		else cout << "No Match Found" << endl << endl;
	}
	void store()
	{
		ofstream File;
		File.open("Contact_file.dat" , ios::app);
		File.write((char*)this , sizeof(*this));
		File.close();
		return;
	}
	void read_from_file()
	{
		ifstream File;
		File.open("Contact_file.dat" , ios::in);

		while (!File.eof())
		{
			File.read((char*)this , sizeof(*this));
		}
		File.close();
	}
};

PhoneBook MyPhone = PhoneBook();


void save_number()
{
	cout << "1. Personal" << endl;
	cout << "2 . Work" << endl;
	cout << "Enter your query type : ";
	int choice;
	cin >> choice;
	string name, number, email;
	cout << "Enter Name : ";
	cin >> name;
	cout << "Enter Number : ";
	cin >> number;
	cout << "Enter email : ";
	cin >> email;

	switch (choice)
	{
	case 1 : {
		string birthday;
		cout << "Enter birthday : ";
		cin >> birthday;
		MyPhone.insert(new Personal(name , number , email , birthday));
	}
	break;
	case 2: {
		string job;
		cout << "Enter job : ";
		cin >> job;
		MyPhone.insert(new Work(name , number , email , job));
	}
	break;
	default :
	{

		system("cls");
		cout << "\n\n\n\t\t Come Again in case you need to call!";
		exit(1);
	}
	break;
	}

}
void search_contact()
{
	string parameter;
	cout << "1. Search by NAME" << endl;
	cout << "2. Search by NUMBER" << endl;
	cout << "3. Search by EMAIL" << endl;
	int choice;
	cin >> choice;
	cout << "Enter query : ";
	cin >> parameter;
	MyPhone.search(parameter , choice);


}
void Operation(int choice)
{
	switch (choice)
	{
	case 1 : save_number();
		break;
	case 2 : search_contact();
		break;
	default : {
		MyPhone.store();
		system("cls");
		cout << "\n\n\n\t\t Come Again in case you need to call!";
		exit(1);
	}
	}
}
int main()
{
	MyPhone.read_from_file();
	MyPhone.search("aa", 1);
	while (1)
	{
		Prompt();
		int choice;
		cin >> choice;
		Operation(choice);

	}
	return 0;

}
