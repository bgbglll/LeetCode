// 338. Counting Bits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		if (num == 0){
			return res;
		}
		for (int i = 1; i <= num; i *= 2){
			res[i] = 1;
		}
		for (int i = 1; i <= num; i++){
			for (int j = 2; i + j <= num; j *= 2){
				if (i == j)continue;
				if (res[i + j] != 0)continue;
				res[i + j] = res[i] + res[j];
			}
		}
		return res;
	}
};
int main()
{
	return 0;
}

