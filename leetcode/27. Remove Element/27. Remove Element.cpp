// 27. Remove Element.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		for (int i = 0; i < n; i++){
			if (nums[i] == val){
				swap(nums[i], nums[n - 1]);
				n--;
				i--;
			}
		}
		return n;
	}
};
int main()
{
	return 0;
}

