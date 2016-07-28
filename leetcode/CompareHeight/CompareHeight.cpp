// CompareHeight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool dfs(unordered_map<int, unordered_set<int>> &mp, int start, int end) {
	if (mp[start].find(end) != mp[start].end())return true;
	for (auto it = mp[start].begin(); it != mp[start].end(); it++) {
		if (dfs(mp, *it, end))return true;
	}
	return false;
}
int cmp(int g1, int g2, vector<vector<int> > records, int n) {
	// write code here
	unordered_map<int, unordered_set<int>> mp;
	for (int i = 0; i < n; i++) {
		mp[records[i][0]].insert(records[i][1]);
	}
	if (dfs(mp, g1, g2)) {
		return 1;
	}
	else if (dfs(mp, g2, g1)) {
		return -1;
	}
	else return 0;

}
int main() {
	int n;
	while (cin >> n) {
		vector<vector<int> > records = { { 1, 2 }, { 2, 4 }, { 2, 3 }, { 3, 5 } };
		cout << cmp(6, 1, records, 4) << endl;
	}

	return 0;
}

