// 300. Longest Increasing Subsequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)return 0;
		int *dp = new int[n];
		for (int i = 0; i<n; i++){
			dp[i] = 1;
		}
		int res = 1;
		for (int i = 1; i<n; i++){
			for (int j = 0; j<i; j++){
				if (nums[i]>nums[j] && dp[j] + 1>dp[i]){
					dp[i] = dp[j] + 1;
					if (dp[i]>res){
						res = dp[i];
					}
				}
			}
		}
		delete[]dp;
		return res;
	}
};

int main()
{
	return 0;
}

