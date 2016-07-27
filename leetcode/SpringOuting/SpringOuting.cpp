// SpringOuting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;
int choose[1005][1005], n, m, half;
bool isGo(int least, int now) {
	int count = 0;
	for (int i = 0; i < n; i++){
		if (choose[i][now] < choose[i][least]) {
			count++;
		}
	}
	if (count >= half)return true;
	return false;
}
int main() {
	while (cin >> n >> m) {
		int t;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				cin >> t;
				choose[i][t] = j;
			}
		}
		half = n / 2 + 1;
		int res = 0;
		for (int i = m; i > 0; i--){
			if (isGo(res, i)) {
				res = i;
			}
		}
		if (res ==0 ) cout << "otaku" << endl;
		else cout << res << endl;				
	}
	return 0;
}

