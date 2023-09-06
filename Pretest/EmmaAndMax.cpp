#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, q;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> p >> q;
    int m = q - p + 1;
    int a[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = p + i;
    }
    int b[m][n];
    int minarr[m];
    for (int i = 0; i < m; i++)
    {
        minarr[i] = INT_MAX;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = abs(a[i] - arr[j]);
            if (b[i][j] == 0)
            {
                minarr[i] = 0;
                break;
            }
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