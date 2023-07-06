#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, m, k;
    cin >> n >> x >> m >> k;
    vector<int> gift(n + 1, x);
    int s = 1;
    int e = 1;
    int n_org = n;
    for (int i = 1; i <= k; i++)
    {
        e = s + m;
        while (e > n)
            e = e - n;
        gift[e]--;
        if (gift[e] == 0)
        {
            n--;
        }
        if (i != k)
        {
            while (gift[e] == 0)
            {
                e--;
                if (e == 0)
                {
                    while (gift[n_org] == 0)
                    {
                        n_org--;
                    }
                    e = n_org;
                }
            }

            s = e;
        }
    }
    cout << e;
    return 0;
}