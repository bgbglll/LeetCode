// 40. Combination Sum II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	void combination(vector<int>& candidates, int target, int start, vector<int> nums, vector<vector<int>> &res){
		if (target == 0){
			if (nums.size())res.push_back(nums);
			return;
		}
		if (target < 0) return;
		for (int i = start; i<candidates.size(); i++){
			if ((i > start) && (candidates[i] == candidates[i - 1])) continue;
			nums.push_back(candidates[i]);
			combination(candidates, target - candidates[i], i + 1, nums, res);
			nums.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> nums;
		vector<vector<int>> res;
		combination(candidates, target, 0, nums, res);
		return res;
	}
};
int main()
{
	return 0;
}

