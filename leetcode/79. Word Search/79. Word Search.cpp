// 79. Word Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	bool helper(vector<vector<char>>& board, string &word, int index, vector<vector<bool>> &visited, int i, int j){
		if (index == word.size()){
			return true;
		}
		int m = board.size(), n = board[0].size();
		for (int k = 0; k<4; k++){
			int i0 = i + dx[k];
			int j0 = j + dy[k];
			if (i0 < m&&i0 >= 0 && j0 < n&&j0 >= 0 && (!visited[i0][j0]) && word[index] == board[i0][j0]){
				visited[i0][j0] = true;
				if (helper(board, word, index + 1, visited, i0, j0))return true;
				visited[i0][j0] = false;
			}
		}
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++){
				if (board[i][j] == word[0]){
					visited[i][j] = true;
					if (helper(board, word, 1, visited, i, j))return true;
					visited[i][j] = false;
				}
			}
		}
		return false;
	}
};

int main()
{
	return 0;
}

