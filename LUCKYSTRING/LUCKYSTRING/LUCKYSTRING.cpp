// LUCKYSTRING.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_set"
#include "string"
#include "set"

using namespace std;

unordered_set<int> getFibonaci() {
	unordered_set<int> res;
	int f1 = 1;
	int f2 = 1;
	res.insert(f1);
	res.insert(f2);
	int f = 0;
	while (f <= 26) {
		f = f1 + f2;
		res.insert(f);
		f1 = f2;
		f2 = f;
	}
	return res;
}

int countDiff(string s) {
	int count = 0;
	vector<int> counts(26, 0);
	for (int i = 0; i < s.length(); i++) {
		if (counts[s[i] - 'a'] == 0)count++;
		++counts[s[i] - 'a'];
	}
	return count;
}
int main() {
	string str;
	unordered_set<int> fib = getFibonaci();
	while (cin >> str) {
		set<string> table;
		for (int i = 0; i < str.size(); ++i) {
			for (int j = i + 1; j <= str.size(); ++j)
			{
				string s = str.substr(i, j - i);
				int diff = countDiff(s);
				if (fib.find(diff) != fib.end())
				{
					table.insert(s);
				}
			}
		}
		//vector<string> res(table.begin(), table.end());
		//sort(res.begin(), res.end());
		for (auto s : table) {
			cout << s << endl;
		}
	}
	return 0;
}

