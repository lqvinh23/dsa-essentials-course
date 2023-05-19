#include <bits/stdc++.h>

using namespace std;

bool canPlace(vector<string> &arr, vector<vector<int>> &res, int r, int c, int n, int m)
{

    if (r >= 0

        and r < n

        and c >= 0

        and c < m

        and arr[r][c] != 'X'

        and res[r][c] != 1)
    {

        return true;
    }

    return false;
}

bool findPath(vector<string> &arr, vector<vector<int>> &res, int r, int c, int n, int m)
{

    if (r == n - 1 and c == m - 1)
    {

        res[r][c] = 1;

        return true;
    }

    if (canPlace(arr, res, r, c, n, m))
    {

        res[r][c] = 1;

        if (findPath(arr, res, r + 1, c, n, m)

            or findPath(arr, res, r, c + 1, n, m)

            or findPath(arr, res, r - 1, c, n, m)

            or findPath(arr, res, r, c - 1, n, m))
        {

            return true;
        }

        res[r][c] = 0;

        return false;
    }
}

int main()
{
    // vector<string> arr{
    //     "OXOOO",
    //     "OOOXO",
    //     "XXXOO",
    //     "XOOOX",
    //     "XXOOO"};

    vector<string> arr{
        "OOOOO",
        "OOOOO",
        "OOXOO",
        "OOOOO",
        "OOOOO"};

    int n = arr.size();

    int m = arr[0].size();

    vector<vector<int>> res(n, vector<int>(m, 0));

    findPath(arr, res, 0, 0, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
