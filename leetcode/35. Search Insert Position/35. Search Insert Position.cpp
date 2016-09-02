// 35. Search Insert Position.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int mid;
		int left = 0, right = nums.size() - 1;
		while (left <= right){
			mid = left + (right - left) / 2;
			if (target<nums[mid]){
				right = mid - 1;
			}
			else if (target>nums[mid]){
				left = mid + 1;
			}
			else if (target == nums[mid]){
				return mid;
			}
		}
		return left;
	}
};
int main()
{
	return 0;
}

