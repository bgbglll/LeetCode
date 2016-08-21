// youdao.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stack>
#include <vector>


using namespace std;


void shuffle(vector<int> &a, int n) {
	stack<int> st1;
	stack<int> st2;
	int i = 0;
	for (; i < n; i++){
		st1.push(a[i]);
	}
	for (; i < 2*n; i++){
		st2.push(a[i]);
	}
	int j = 2*n-1;
	int flag = 0;
	while (j >= 0){
		if (flag == 0){
			a[j] = st2.top();
			st2.pop();
			flag = 1 - flag;
		}
		else {
			a[j] = st1.top();
			st1.pop();
			flag = 1 - flag;
		}
		j--;
	}
}
int main()
{
	int T;
	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	while (cin >> T) {
		while (T--){
			int n, k;
			cin >> n >> k;
			vector<int> a;
			int m = 2 * n;
			while (m--){
				int tmp;
				cin >> tmp;
				a.push_back(tmp);
			}
			while (k--){
				shuffle(a, n);
			}
			for (int i = 0; i < 2 * n; i++){
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

