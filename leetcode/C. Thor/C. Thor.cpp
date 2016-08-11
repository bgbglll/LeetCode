// C. Thor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int main()
{
	int n, q;
	while (cin >> n >> q){
		int t, x;
		vector<pair<int, int> > res;
		int unread = 0;
		while (q--) {
			cin >> t >> x;
			if (t == 1) {
				res.push_back(make_pair(x, 0));
				unread++;
			}
			else if(t==2){
				for (int i = 0; i < res.size();i++){
					if (res[i].first == x){
						if (res[i].second == 0) {
							unread--;
						}
						res[i].second = 1;
						
					}
				}
			}
			else {
				for (int i = 0; i < x; i++){
					if (res[i].second == 0) {
						unread--;
					}
					res[i].second = 1;
				}
			}
			cout << unread << endl;
		}
	}
	return 0;
}

