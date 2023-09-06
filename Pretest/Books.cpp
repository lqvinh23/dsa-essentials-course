#include <bits/stdc++.h>
using namespace std;

int n;
long long t;
int books[100005];
int ans = 0;

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> books[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long sumt = 0;
        int tmp = 0;
        for (int j = i; j <= n; j++)
        {
            sumt += books[j];
            if (sumt > t)
            {
                tmp = j - i;
                break;
            }
        }
        if (sumt <= t)
        {
            tmp = n - i + 1;
            ans = max(ans, tmp);
            break;
        }
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}