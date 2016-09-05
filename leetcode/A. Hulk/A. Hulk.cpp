// A. Hulk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

string love = "I love";
string hate = "I hate";

int main()
{
	int n;
	while (cin >> n) {
		bool flag = true;
		for (int i = 1; i <= n; i++){
			if (flag){
				cout << hate;
				flag = false;
			}
			else {
				cout << love;
				flag = true;
			}
			if (i == n){
				cout << " it" << endl;
			}
			else {
				cout << " that ";
			}
		}
	}
	return 0;
}

