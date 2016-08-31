// A. Bus to Udayland.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	//FILE *stream;
	//freopen_s(&stream, "input.txt", "r", stdin);
	//freopen_s(&stream, "output.txt", "w", stdout);
	int n;
	while (cin >> n) {
		getchar();
		vector<string> str;
		while (n--) {
			string tmp;
			getline(cin, tmp);
			str.push_back(tmp);
		}
		int m = str.size();
		bool res = false;
		for (int i = 0; i < m; i++) {
			if (str[i][0] == 'O' && str[i][1] == 'O') {
				str[i][0] = '+';
				str[i][1] = '+';
				res = true;
				break;
			}
			if (str[i][3] == 'O' && str[i][4] == 'O') {
				str[i][3] = '+';
				str[i][4] = '+';
				res = true;
				break;
			}
		}
		if (res) {
			cout << "YES" << endl;
			for (int i = 0; i < m; i++) {
				cout << str[i] << endl;
			}
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

