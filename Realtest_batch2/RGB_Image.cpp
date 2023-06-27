#include <bits/stdc++.h>
using namespace std;

int n, m;
int Rs = 0;
int Gs = 0;
int Bs = 0;
vector<vector<char>> a(105, vector<char>(105));

void bfs(int s1, int s2)
{
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            switch (a[i][j])
            {
            case 'R':
                Rs++;
                break;
            case 'G':
                Gs++;
                break;
            case 'B':
                Bs++;
                break;
            default:
                break;
            }
        }
    }

    return 0;
}