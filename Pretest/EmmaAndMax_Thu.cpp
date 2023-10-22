#include <bits/stdc++.h>
using namespace std;

int n, M;
int a[100005];
int p, q;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> p >> q;

    long long valMin_P = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        valMin_P = min(valMin_P, (long long)abs(a[i] - p));
    }
    M = p;

    for (int i = 0; i < n - 1; i++)
    {
        long long t = (a[i] + a[i + 1]) / 2;
        if (p <= t && t <= q && t - a[i] > valMin_P)
        {
            valMin_P = t - a[i];
            M = t;
        }
    }

    long long valMin_Q = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        valMin_Q = min(valMin_Q, (long long)abs(a[i] - q));
    }

    if (valMin_Q > valMin_P)
    {
        M = q;
    }
    cout << M << endl;
    return 0;
}