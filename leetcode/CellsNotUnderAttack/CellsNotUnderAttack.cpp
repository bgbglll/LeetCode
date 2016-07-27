// CellsNotUnderAttack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>


using namespace std; 
int row[100005] = { 0 }, col[100005] = {0};

int main() {
	int n, m;
	while (cin >> n >> m) {
		long long sum = 1LL * n * n;
		int r = 0, c = 0;
		int x, y;
		for (int i = 1; i <= m; i++) {
			cin >> x >> y;
			if (!row[x]) {
				sum = sum - (n - c);			
			}
			if (!col[y]) {
				sum = sum - (n - r);				
			}
			if ((!row[x])&&(!col[y])) {
				sum++;
			}
			if (!row[x]) {
				r++;
			}
			if (!col[y]) {
				c++;
			}
			row[x] = col[y] = 1;
			cout << sum << " ";
		}
		
	}
	return 0;
}

