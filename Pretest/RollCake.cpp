#include <bits/stdc++.h>
using namespace std;

int n, m;
int cakes[1005];
int maxCakes = 0;

bool cmp(int a, int b)
{
    // if (a == 10)
    //     return true;
    // else if (b == 10)
    //     return false;
    if (a % 10 == 0 || b % 10 == 0)
    {
        if (a % 10 == 0 && b % 10 == 0)
            return (a < b);
        else if (a % 10 == 0)
            return true;
        else
            return false;
    }
    else
        return (a > b);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> cakes[i];
    }

    sort(cakes, cakes + n, cmp);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << cakes[i] << " ";
    // }

    for (int i = 0; i < n; i++)
    {
        // cout << i << ": ";
        if (m == 0)
            break;
        if (cakes[i] < 10)
            continue;
        if (cakes[i] == 10)
        {
            maxCakes++;
            continue;
        }
        while (cakes[i] > 10)
        {
            cakes[i] -= 10;
            maxCakes++;
            m--;
            if (m == 0)
            {
                break;
            }
        }

        if (cakes[i] == 10)
            maxCakes++;
    }

    cout << maxCakes;
    return 0;
}
