
#include <iostream>
using namespace std;

bool canPlace(int board[][20], int n, int x, int y)
{

    // Column
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
        }
    }
    // Left Diag
    int i = x;
    int j = y;
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    // Right Diag
    i = x;
    j = y;
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void printBoard(int n, int board[][20])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveNQueen(int n, int board[][20], int i)
{
    // base case
    if (i == n)
    {
        // Print the board
        printBoard(n, board);
        return true;
    }

    // rec case
    // try to place a queen in every row
    for (int j = 0; j < n; j++)
    { // loop through all the column to see which position can the queen be placed
        // whether the current i,j is safe or not
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNQueen(n, board, i + 1);
            if (success)
            {
                return true;
            }
            // backtrack
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    // your code goes here
    int board[20][20] = {0};
    int n;
    cin >> n;

    printBoard(n, board);

    solveNQueen(n, board, 0);

    printBoard(n, board);

    return 0;
}
