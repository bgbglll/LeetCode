// ImplementTrie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode *next[26];
	bool isWord;
	TrieNode() {
		for (int i = 0; i < 26; i++){
			next[i] = NULL;
		}
		isWord = false;
	}
};


class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode *p = root;
		int len = word.length();
		for (int i = 0; i < len; i++) {
			int t = word[i] - 'a';
			if (p->next[t] == NULL) {
				p->next[t] = new TrieNode();
			}
			p = p->next[t];
		}
		p->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *p = root;
		int len = word.length();
		for (int i = 0; i < len; i++) {
			int t = word[i] - 'a';
			if (p->next[t] == NULL) {
				return false;
			}
			p = p->next[t];
		}
		if (p->isWord == true)return true;
		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *p = root;
		int len = prefix.length();
		for (int i = 0; i < len; i++) {
			int t = prefix[i] - 'a';
			if (p->next[t] == NULL) {
				return false;
			}
			p = p->next[t];
		}	
		return true;
	}

private:
	TrieNode* root;
};
int main() {

	return 0;
}

