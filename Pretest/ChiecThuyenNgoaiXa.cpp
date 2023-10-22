#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[10], A, B;
int permutation[10];
bool flag[10];
int ans = 1e9;

int getCost(vector<pair<int, int>> path)
{
    int res = 0;
    int cnt = 0;
    int len = path.size();
    for (int i = 0; i < len - 1; i++)
    {
        res += (abs(path[i].first - path[i + 1].first) + abs(path[i].second - path[i + 1].second)) * cnt;
        cnt++;
    }
    return res;
}

void gen(int i, int n)
{
    if (i > n)
    {
        // for (int j = 1; j <= n; j++)
        // {
        //     cout << permutation[j];
        // }
        // cout << endl;
        for (int split = 0; split <= n; split++)
        {
            vector<pair<int, int>> pathA;
            pathA.push_back(A);
            for (int t = 1; t <= split; t++)
                pathA.push_back(a[permutation[t]]);
            pathA.push_back(A);

            vector<pair<int, int>> pathB;
            pathB.push_back(B);
            for (int t = split + 1; t <= n; t++)
                pathB.push_back(a[permutation[t]]);
            pathB.push_back(B);

            int val = getCost(pathA) + getCost(pathB);
            ans = min(ans, val);
        }
        return;
    }

    for (int j = 1; j <= n; j++)
    {
        if (flag[j] == true)
            continue;
        permutation[i] = j;
        flag[j] = true;
        gen(i + 1, n);
        flag[j] = false;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;

    gen(1, n);

    cout << ans;

    return 0;
}