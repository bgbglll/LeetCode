// 260. Single Number III.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res;
		int n = nums.size();
		if (n == 0)return res;
		int bit = 0;
		for (int i = 0; i<n; i++){
			bit ^= nums[i];
		}
		bit = bit&(~(bit - 1));
		int A = 0, B = 0;
		for (int i = 0; i<n; i++){
			if ((nums[i] & bit) == 0){
				A ^= nums[i];
			}
			else
				B ^= nums[i];
		}
		return vector<int>({ A, B });
	}
};
int main()
{
	return 0;
}

