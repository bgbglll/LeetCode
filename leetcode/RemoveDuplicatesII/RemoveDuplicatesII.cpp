// RemoveDuplicatesII.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <unordered_map>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int i = 0;
	for (int n : nums)
		if (i < 2 || n > nums[i - 2])
			nums[i++] = n;
	return i;
}
int main() {
	int n;
	while (cin >> n) {
		int t;
		vector<int> nums;
		while (n--) {
			cin >> t;
			nums.push_back(t);
		}
		cout << removeDuplicates(nums) << endl;
	}
	
	return 0;
}

