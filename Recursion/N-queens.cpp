#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int duprow = row;
        int dupcol = col;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        col = dupcol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        // Base Case:
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        // Main Case
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                solve(col + 1, board, ans, n);
                board[row][col] = '.'; // backtracking step ; ommitting the filled space
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        solve(0, board, ans, n);
        return ans;
    }
};
int main()
{

    return 0;
}