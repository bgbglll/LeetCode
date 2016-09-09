// 38. Count and Say.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		if (n == 1)return s;
		int i = 0;
		int times = 1;
		while (--n){
			string tmp = "";
			for (i = 0; i<s.size(); i++){
				if (s[i] == s[i + 1])times++;
				else{
					//cout << char(times+'0') << endl;
					tmp = tmp + char(times + '0') + char(s[i]);
					times = 1;
				}
			}
			s = tmp;
			//cout << s << endl;
		}
		return s;
	}
};

int main() {
	return 0;
}

