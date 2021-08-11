#pragma once
#include <bits/stdc++.h>
#include "Contact.h"
#include "Trie.h"
#include "work.h"
#include "personal.h"
#include "PhoneBook.h"
PhoneBook::PhoneBook()
{
    names = new Trie();
    email = new Trie();
    numbers = new Trie();
}
void PhoneBook:: print(int i)
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


void PhoneBook:: insert(Contact* contact)
{

    NAMES[contact->Name].push_back(contact);

    EMAILS[contact->Email].push_back(contact);

    NUMBERS[contact->Number].push_back(contact);

    names->insert(contact->Name);

    numbers->insert(contact->Number);

    email->insert(contact->Email);


}

void PhoneBook:: search(string prefix , int i)
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
