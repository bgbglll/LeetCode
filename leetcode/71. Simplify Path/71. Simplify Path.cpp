// 71. Simplify Path.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std; 

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> dirs;
		for (auto i = path.begin(); i != path.end();) {
			++i;
			auto j = find(i, path.end(), '/');
			auto dir = string(i, j);
			if (!dir.empty() && dir != ".") {// 当有连续'///' 时，dir 为空
				if (dir == "..") {
					if (!dirs.empty())
						dirs.pop_back();
				}
				else
					dirs.push_back(dir);
			}
			i = j;
		}
		stringstream out;
		if (dirs.empty()) {
			out << "/";
		}
		else {
			for (auto dir : dirs)
				out << '/' << dir;
		}
		return out.str();
	}
};

int main()
{
	return 0;
}

