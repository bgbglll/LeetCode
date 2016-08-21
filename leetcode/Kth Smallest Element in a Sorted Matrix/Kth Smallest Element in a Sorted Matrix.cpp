// Kth Smallest Element in a Sorted Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;


int kthSmallest(vector<vector<int>>& matrix, int k) {
	int m = matrix[0].size();
	int i = k / m;
	int j = k % m;
	return matrix[i][j];
}

int main()
{
	return 0;
}

