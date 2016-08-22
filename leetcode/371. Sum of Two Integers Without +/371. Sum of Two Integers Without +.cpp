// 371. Sum of Two Integers Without +.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;


int getSum(int a, int b) {
	int sum = a;
	while (b != 0) {
		sum = a ^ b;
		b = (a&b) << 1;
		a = sum;
	}

	return sum;
}
int main()
{
	int a, b;
	while (cin >> a >> b) {
		cout << getSum(a, b) << endl;
	}
	return 0;
}

