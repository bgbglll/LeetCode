// 238. Product of Array Except Self.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int product = 1;
		int flag = 0;
		for (int i = 0; i<nums.size(); i++){
			if (nums[i] == 0){
				flag++;
				continue;
			}
			product *= nums[i];
		}
		vector<int> res;
		for (int i = 0; i<nums.size(); i++){
			if (flag>1){
				res.push_back(0);
			}
			else if (flag == 1){
				if (nums[i] == 0)
					res.push_back(product);
				else{
					res.push_back(0);
				}
			}
			else
				res.push_back(product / nums[i]);
		}
		return res;
	}
};

int main()
{
	return 0;
}

