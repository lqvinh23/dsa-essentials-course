#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, q;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> p >> q;
    int m = q - p + 1;
    int *a = new int[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = p + i;
    }
    int **b = new int *[m];
    for (int i = 0; i < n; i++)
    {
        b[i] = new int[n];
    }
    int *minarr = new int[m];
    for (int i = 0; i < m; i++)
    {
        minarr[i] = INT_MAX;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = (a[i] - arr[j] > 0) ? (a[i] - arr[j]) : (arr[j] - a[i]);
            if (minarr[i] > b[i][j])
                minarr[i] = b[i][j];
        }
    }

    int maxofmin = 0;
    for (int i = 0; i < m; i++)
    {
        maxofmin = max(maxofmin, minarr[i]);
    }
    // cout << maxofmin << endl;
    for (int i = 0; i < m; i++)
    {
        if (minarr[i] == maxofmin)
        {
            cout << a[i];
            break;
        }
    }
    return 0;
}