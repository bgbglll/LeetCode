// Cards.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <algorithm>

using namespace std;

struct data{
	int val;
	int location;
};

bool comp(data x, data y) {
	return x.val < y.val;
}
int main() {
	int t;
	while (cin >> t){
		data a[105] = {0};
		int n;
		for (int i = 1; i <= t; i++) {
			cin >> n;
			a[i].location = i;
			a[i].val = n;
		}

		sort(a + 1, a + t + 1, comp);

		for (int i = 1, j = t; i <= t / 2; i++, j--)
		{
			//printf("%d %d \n", a[i].location, a[j].location);
			cout << a[i].location << " " << a[j].location << endl;
		}

	}
}

