// youdao2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point{
	int x;
	int y;
};

bool cmp(Point a, Point b){
	return (a.x<b.x)&&(a.y<b.y);
}

bool operator<(const Point &l, const Point &r)
{
	return cmp(l, r);
}
int main()
{
	int T;
	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);

	while (cin >> T) {
		vector<Point> p;
		while (T--){
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			Point p1,p2;
			p1.x = x1;
			p1.y = y1;
			p2.x = x2;
			p2.y = y2;
			p.push_back(p1);
			p.push_back(p2);
		}
		sort(p.begin(), p.end());
		auto res1 = p.begin();
		auto res2 = p.end() - 1;
		cout << res1->x << " " << res1->y << " " << res2->x << " " << res2->y << endl;
	}
	return 0;
}

