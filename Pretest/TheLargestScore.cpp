#include <bits/stdc++.h>
using namespace std;

int getScore(int n, int A[])
{
    int res = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (A[i] == A[i - 1])
            cnt++;
        else
            cnt = 1;
        res = max(res, cnt);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            int tmpAns = getScore(n, a);
            ans = max(tmpAns, ans);
        }
        else
        {
            int tmp = a[i];
            a[i] = a[i - 1];
            int tmpAns = getScore(n, a) - 1;
            ans = max(tmpAns, ans);
            a[i] = tmp;
        }
    }

    cout << ans;
    return 0;
}