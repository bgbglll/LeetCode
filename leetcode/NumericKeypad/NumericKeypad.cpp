// NumericKeypad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "string" 
#include "iostream"
#include "cstring"
#define MAX 600
using namespace std;

int T;
char K[MAX];
int S[MAX];
int length;
int result[MAX];
//go[i][j] = true，表示可以从数字i移动到数字j
bool go[10][10] = {
	{ true, false, false, false, false, false, false, false, false, false }, //0
	{ true, true, true, true, true, true, true, true, true, true }, //1
	{ true, false, true, true, false, true, true, false, true, true }, //2
	{ false, false, false, true, false, false, true, false, false, true }, //3
	{ true, false, false, false, true, true, true, true, true, true }, //4
	{ true, false, false, false, false, true, true, false, true, true }, //5
	{ false, false, false, false, false, false, true, false, false, true }, //6
	{ true, false, false, false, false, false, false, true, true, true }, //7
	{ true, false, false, false, false, false, false, false, true, true }, //8
	{ false, false, false, false, false, false, false, false, false, true }, //9
};

bool dfs(int depth, int last, bool below)
{
	int i, j;
	if (depth >= length)
	{
		/*
		// 找到一个合法解
		// 由于我们总是从高到低对数字进行枚举，因此第一个找到的解一定是最大解
		*/
		return true;
	}

	if (below == true)
	{
		/*
		已经有高位小于S的对应位置
		将后面的数位填充为last能够移动到的最大数字
		*/
		for (j = 9; j >= 0; j--)
			if (go[last][j] == true)
				break;
		for (i = depth; i<length; i++)
			result[i] = j;

		return true;
	}

	for (i = 9; i >= 0; i--)
	{
		if (i <= S[depth] && go[last][i])
		{
			result[depth] = i;
			if (dfs(depth + 1, i, i < S[depth]))
				return true;
		}
	}
	return false;
}

int main()
{
	cin >> T;
	int i, j;
	for (i = 0; i<T; i++)
	{
		cin >> K;
		length = strlen(K);
		memset(result, -1, sizeof(S));
		for (j = 0; j<length; j++)
			S[j] = K[j] - '0';

		dfs(0, 1, false);
	

		for (j = 0; j<length; j++)
			cout << result[j];
		cout << endl;
	}

	return 0;
}


