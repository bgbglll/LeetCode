// 46. Permutations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > ret;
		dfs(ret, num, 0);
		return ret;
	}

	void dfs(vector<vector<int> >& ret, vector<int>& num, int cur)
	{
		if (num.size() == cur)
		{
			ret.push_back(num);
		}
		else
		{
			for (int i = cur; i < num.size(); ++i)
			{
				swap(num[cur], num[i]);
				dfs(ret, num, cur + 1);
				swap(num[cur], num[i]);
			}
		}
	}
};

int main()
{
	return 0;
}

