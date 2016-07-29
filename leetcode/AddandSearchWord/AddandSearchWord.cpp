// AddandSearchWord.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;

struct Trie {
	bool isWord;
	Trie *next[26];
	Trie() {
		for (int i = 0; i < 26; i++){
			next[i] = NULL;
		}
	}
};
Trie *root = new Trie();
void addWord(string word) {
	Trie *p = root;
	int len = word.length();
	for (int i = 0; i < len; i++) {
		int t = word[i] - 'a';
		if (p->next[t] == NULL){
			p->next[t] = new Trie();
		}
		p = p->next[t];
	}
	p->isWord = true;
}
bool search(string word) {
	Trie *p = root;
	int len = word.length();
	for (int i = 0; i < len; i++) {
		if (word[i] == '.'){
			for (int j = 0; j < 26; j++){
				if (p->next[j]){
					word[i] = 'a' + j;
					if (search(word))
						return true;
				}
			}
			return false;
		}
		int t = word[i] - 'a';
		if (p->next[t] == NULL){
			return false;
		}
		p = p->next[t];
	}
	if (p->isWord) return true;
	return false;
}
int main()
{
	int n;
	while (cin >> n){
		addWord("bad");
		addWord("dad");
		addWord("mad");
		cout << search(".ad");
		cout<<search("pad");
		cout<<search("bad");
		cout << search("b..");
	}
	return 0;
}

