#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long ans = 0;
    int n;
    long long a[5005];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = n - 1; i >= 2; i--)
    {
        int l = 0;
        int r = i - 1;
        while (l < r)
        {
            if (a[l] + a[r] > a[i])
            {
                if ((a[l] == a[r]) && (a[r] != a[i]))
                {
                    ans += r - l;
                }
                if ((a[l] != a[r]) && (a[r] == a[i]))
                {
                    ans++;
                }
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