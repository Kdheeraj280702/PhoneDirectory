#pragma once
#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
	Trie* prefix[300];
	bool EndOfTheWord;
	Trie();
	void insert(string prefix);
	void Suggestions(Trie*, string, vector<string>&);
	bool search(string , vector<string>&);
};
