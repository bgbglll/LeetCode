// FindKth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

int pivot(vector<int> &a, int left, int right) {
	int j = left - 1;
	int q = a[right];
	for (int i = left; i < right; i++){
		if (a[i] > q){
			swap(a[i], a[++j]);
		}
	}
	swap(a[right], a[++j]);
	return j;
}
void quickSort(vector<int> &a, int left,int right){
	if (left < right) {
		int q = pivot(a, left, right);
		quickSort(a, q + 1, right);
		quickSort(a, left, q - 1);
	}
}
int helper(vector<int> &a, int left, int right, int k) {
	int q = pivot(a, left, right);
	if (k == q - left + 1) return a[q];
	else if (k > q - left + 1) return helper(a, q + 1, right, k - q + left - 1);
	else return helper(a, left, q - 1, k);
}
int findKth(vector<int> a, int n, int K) {
	// write code here
	return helper(a, 0, n - 1, K);
}
int main()
{
	int n;
	while (cin >> n){
		vector<int> a = { 1, 6, 5, 4, 2 };
		//quickSort(a, 0, 4);
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << endl;
		}
		cout << findKth(a, 5, n);
	}
	return 0;
}

