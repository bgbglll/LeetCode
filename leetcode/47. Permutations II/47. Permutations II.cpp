// 47. Permutations II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		int n = nums.size();
		if (n == 0)return res;
		dfs(nums, 0, res);
		return res;
	}
	void dfs(vector<int> nums, int start, vector<vector<int>> &res){
		if (start == nums.size()){
			res.push_back(nums);
			return;
		}
		unordered_map<char, int> uq;
		for (int i = start; i<nums.size(); i++){
			if (uq[nums[i]] == 0){
				uq[nums[i]]++;
				swap(nums[start], nums[i]);
				dfs(nums, start + 1, res);
				swap(nums[start], nums[i]);
			}
		}
	}
};
int main()
{
	return 0;
}

