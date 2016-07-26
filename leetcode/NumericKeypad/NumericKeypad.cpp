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
//go[i][j] = true����ʾ���Դ�����i�ƶ�������j
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
		// �ҵ�һ���Ϸ���
		// �����������ǴӸߵ��Ͷ����ֽ���ö�٣���˵�һ���ҵ��Ľ�һ��������
		*/
		return true;
	}

	if (below == true)
	{
		/*
		�Ѿ��и�λС��S�Ķ�Ӧλ��
		���������λ���Ϊlast�ܹ��ƶ������������
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


