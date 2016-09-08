// 34. Search for a Range.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>

using namespace std;

class Solution {
public:
	int findFirstK(vector<int>& nums, int target){
		int left = 0, right = nums.size() - 1;
		int mid = 0;
		while (left <= right){
			mid = left + (right - left) / 2;
			if (nums[mid] == target){
				if (mid == left || nums[mid - 1] != nums[mid]){
					return mid;
				}
				right = mid - 1;
			}
			else if (target<nums[mid]){
				right = mid - 1;
			}
			else left = mid + 1;
		}
		return -1;
	}

	int findLastK(vector<int>& nums, int target){
		int left = 0, right = nums.size() - 1;
		int mid = 0;
		while (left <= right){
			mid = left + (right - left) / 2;
			if (nums[mid] == target){
				if (mid == right || nums[mid + 1] != nums[mid]){
					return mid;
				}
				left = mid + 1;
			}
			else if (target<nums[mid]){
				right = mid - 1;
			}
			else left = mid + 1;
		}
		return -1;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		if (nums.size() == 0)return res;
		int l = findFirstK(nums, target);
		int r = findLastK(nums, target);
		res.push_back(l);
		res.push_back(r);
		return res;
	}
};

int main()
{
	return 0;
}

