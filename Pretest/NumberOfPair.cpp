#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int ans = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        ans++;
        // cout << i << i + 1 << endl;
        for (int j = i + 2; j <= n; j++)
        {
            bool isWrong = false;
            bool isValid = true;
            for (int k = i + 1; k < j; k++)
            {
                if (a[k] >= a[i] || a[k] >= a[j])
                {
                    if (a[k] >= a[i])
                    {
                        isWrong = true;
                    }
                    isValid = false;
                    break;
                }
            }
            if (isValid)
            {
                // cout << i << j << endl;
                ans++;
            }
            if (isWrong)
            {
                break;
            }
        }
    }

    cout << ans;
    return 0;
}