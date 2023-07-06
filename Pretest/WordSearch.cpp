#include <bits/stdc++.h>
using namespace std;

string s;
int n, m;
vector<vector<char>> board(105, vector<char>(105));

bool search(int row, int col, int x)
{
    // base case
    if (x == s.length())
    {
        return true;
    }
    if (row <= 0 || col <= 0 || row > n || col > n)
    {
        return false;
    }

    // recursive case
    if (board[row][col] == s[x])
    {
        board[row][col] = ' ';
        if (search(row + 1, col, x + 1) || search(row - 1, col, x + 1) || search(row, col + 1, x + 1) || search(row, col - 1, x + 1) || search(row + 1, col + 1, x + 1) || search(row - 1, col + 1, x + 1) || search(row + 1, col - 1, x + 1) || search(row - 1, col - 1, x + 1))
        {
            board[row][col] = s[x];
            return true;
        }
        board[row][col] = s[x];
    }
    return false;
}

int main()
{
    cin >> s;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        string tmpStr;
        cin >> tmpStr;
        tmpStr = " " + tmpStr;
        for (int j = 1; j <= m; j++)
        {
            board[i][j] = tmpStr[j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == s[0])
            {
                if (search(i, j, 0))
                {
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}
