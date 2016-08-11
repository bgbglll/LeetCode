// wordPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool wordPattern(string pattern, string str) {
	if (str.find(" ") == string::npos && pattern.size() == 1){
		return true;
	}
	else if (str.find(" ") == string::npos)
		return false;
	unordered_map<char, string> mp;
	unordered_map<string, char> mp2;
	int n = pattern.length();
	int m = str.length();
	int j = 0;
	int i = 0;
	int pre = 0;
	while (i <= m) {
		if (str[i] == ' ' || i==m){
			string tmp = str.substr(pre, i-pre);
			if (mp.find(pattern[j]) == mp.end() && mp2.find(tmp)==mp2.end()){
				mp[pattern[j]] = tmp;
				mp2[tmp] = pattern[j];
			}
			else if (mp[pattern[j]] != tmp){
				return false;
			}
			j++;
			pre = i + 1;
		}
		i++;
	}
	return true;
}


int main()
{
	string s1, s2;
	while (cin >> s1 ){
		getchar();
		getline(cin, s2);
		cout << wordPattern(s1, s2) << endl;
	}

	return 0;
}

