// 387. First Unique Character in a String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

int firstUniqChar(string s) {
	int n = s.length();
	if (n == 0)return -1;
	int a[256] = { 0 };
	for (int i = 0; i<n; i++) {
		a[s[i] - '0']++;
	}
	for (int i = 0; i<n; i++) {
		if (a[s[i] - '0'] == 1){
			return i;
		}
	}
	return -1;
}

int main()
{
	return 0;
}

