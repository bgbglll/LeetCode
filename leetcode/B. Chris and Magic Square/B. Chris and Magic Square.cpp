// B. Chris and Magic Square.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>

using namespace std;

long long a[501][501];
int n;

bool ok()
{
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[1][i];

	for (int i = 2; i <= n; i++)
	{
		long long s = 0;
		for (int j = 1; j <= n; j++)
			s += a[i][j];
		if (s != sum)return false;
	}
	for (int i = 1; i <= n; i++)
	{
		long long s = 0;
		for (int j = 1; j <= n; j++)
			s += a[j][i];
		if (s != sum)return false;
	}
	long long s1 = 0, s2 = 0;
	for (int i = 1; i <= n; i++)
	{
		s1 += a[i][i];
		s2 += a[i][n - i + 1];
	}
	if (s1 != sum || s2 != sum)return false;
	return true;
}

int main()
{
	int x, y;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0){ x = i; y = j; }
		}
	if (n == 1){ cout << 1; return 0; }
	if (x == 1)
	{
		long long s = 0;
		for (int i = 1; i <= n; i++)
		{
			s += a[2][i];
			s -= a[1][i];
		}
		a[x][y] = s;
		if (ok() && s>0){ cout << s; return 0; }
		else{ cout << -1; return 0; }
	}
	else
	{
		long long s = 0;
		for (int i = 1; i <= n; i++)
		{
			s += a[x - 1][i];
			s -= a[x][i];
		}
		a[x][y] = s;
		if (ok() && s>0){ cout << s; return 0; }
		else{ cout << -1; return 0; }
	}
	return 0;
}

