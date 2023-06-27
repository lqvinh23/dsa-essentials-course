#include <bits/stdc++.h>
using namespace std;

map<int, int> searchFirst(vector<vector<char>> &board, string word, int m, int n)
{
    map<int, int> pos;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == word[0])
            {
                cout << row << " ";
                cout << col << endl;
                pos.insert(pair<int, int>(row, col));
            }
        }
    }
    return pos;
}

bool search(vector<vector<char>> &board, string word, int length, int row, int col, int m, int n, int x)
{
    // base case
    if (x == length)
    {
        return true;
    }

    if ((col >= n) or (row >= m) or (col < 0) or (row < 0))
    {
        return false;
    }
    // recursive case
    if (board[row][col] == word[x])
    {
        board[row][col] = ' ';
        if (search(board, word, length, row, col + 1, m, n, x + 1) or search(board, word, length, row, col - 1, m, n, x + 1) or search(board, word, length, row + 1, col, m, n, x + 1) or search(board, word, length, row - 1, col, m, n, x + 1))
        {
            board[row][col] = word[x];
            return true;
        }
        board[row][col] = word[x];
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'E', 'S', 'E', 'E'}};
    string word = "ESE";
    int length = word.size();
    int m = board.size();
    int n = board[0].size();
    map<int, int> firstPos;
    firstPos = searchFirst(board, word, m, n);
    for (auto const &p : firstPos)
    {
        int row = p.first;
        cout << row << " ";
        int col = p.second;
        cout << col << " ";
        bool success = search(board, word, length, row, col, m, n, 0);
        if (success)
        {
            cout << "True" << endl;
        }
        else
            cout << "False" << endl;
    }

    for (auto r : board)
    {
        for (auto c : r)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}