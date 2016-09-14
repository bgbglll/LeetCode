// 42. Trapping Rain Water.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n <= 2) return 0;
		int max = -1, maxInd = 0;
		int i = 0;
		for (; i < n; ++i){
			if (height[i] > max){
				max = height[i];
				maxInd = i;
			}
		}
		int area = 0, root = height[0];
		for (i = 0; i < maxInd; ++i){
			if (root < height[i]) root = height[i];
			else area += (root - height[i]);
		}
		for (i = n - 1, root = height[n - 1]; i > maxInd; --i){
			if (root < height[i]) root = height[i];
			else area += (root - height[i]);
		}
		return area;
	}
};
int main()
{
	return 0;
}

