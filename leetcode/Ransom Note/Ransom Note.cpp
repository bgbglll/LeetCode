// Ransom Note.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
	unordered_map<char,int> mp;
	for (auto s : magazine) {
		mp[s]++;
	}
	for (auto str : ransomNote) {
		if (mp[str] == 0)return false;
		mp[str]--;
	}
	return true;

}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2){
		cout << canConstruct(s1, s2);
	}
	return 0;
}

