// youdao3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	while (cin >> T) {
		while (T--) {
			int n;
			cin >> n;
			vector<int> res(n, 0);
			int k = 2;
			int cur = 1;
			int i = -1;
			while (cur <= n) {
				while (k != 0){
					i++;
					if (i == n)i = 0;
					if (res[i] == 0){
						k--;
					}
					
				}
				k = 2;
				res[i] = cur;
				cur++;
			}
			for (int i = 0; i < n;i++){
				if (i != n - 1){
					cout << res[i] << " ";
				}
				else {
					cout << res[i];
				}
			}
			cout << endl;
		}
	}
	return 0;
}

