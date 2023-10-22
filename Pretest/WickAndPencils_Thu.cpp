#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = n - 1; i >= 2; i--)
    {
        int l = 0, r = i - 1;
        while (l < r)
        {
            if (a[l] + a[r] > a[i])
            {
                ans += r - l;
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    cout << ans;
    return 0;
}