#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
	Trie* prefix[300];
	bool EndOfTheWord;
	Trie()
	{
		for (int i = 0; i < 300; i++)
			prefix[i] = NULL;
		EndOfTheWord = 0;
	}
	void insert(string prefix);
	void Suggestions(Trie*, string, vector<string>&);
	bool search(string , vector<string>&);
};

void Trie::insert(string prefix)
{
	Trie* temp = this;
	for (auto i : prefix)
	{
		if (temp->prefix[i - '0'] == NULL) temp->prefix[i - '0'] = new Trie();
		temp = temp->prefix[i - '0'];
	}
	temp->EndOfTheWord = 1;
}

void Trie::Suggestions(Trie* root , string current , vector<string>& Recommendations)
{
	if (root->EndOfTheWord) Recommendations.push_back(current);
	for (int i = 0; i < 300; i++)
	{
		Trie* next = root->prefix[i];
		if (next)
		{
			current += (i + '0');
			Suggestions(next , current, Recommendations );
			current.pop_back();
		}
	}
	return;
}

bool Trie::search(string s , vector<string>& Recommendations)
{
	Trie* temp = this;
	for (auto i : s)
	{
		if (!temp->prefix[i - '0']) return 0;
		temp = temp->prefix[i - '0'];
	}
	Suggestions(temp , s , Recommendations);
	return 1;
}