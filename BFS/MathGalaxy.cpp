#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int s, e1, e2;
int ans1, ans2;
bool visited[10000];
int d[8] = {1000, -1000, 100, -100, 10, -10, 1, -1};
int dist[10000];

void InputData()
{
    cin >> s >> e1 >> e2;
}

int numOfFactors(int x)
{
    if (x % 2 == 0)
    {
        return int(log2(x)) + 1;
    }

    int ret = 0;
    for (int i = 1; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            ret++;
        }
    }
    return ret + 1;
}

bool isValid(int curE, int newE)
{
    if (newE >= 10000 || newE < 1000 || abs(numOfFactors(curE) - numOfFactors(newE)) > 1)
        return false;
    return true;
}

int bfs(int e)
{
    for (int i = 0; i <= 10000; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i <= 10000; i++)
    {
        dist[i] = 0;
    }
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int curE = q.front();
        q.pop();
        for (int j = 1; j <= 9; j++)
        {
            for (int i = 0; i < 8; i++)
            {
                int newE = curE + j * d[i];
                if (isValid(curE, newE) && visited[newE] == false)
                {
                    visited[newE] = true;
                    dist[newE] = dist[curE] + 1;
                    q.push(newE);
                    if (newE == e)
                        return dist[newE];
                }
            }
        }
    }
    return -1;
}

int main()
{
    InputData();

    if (s == e1)
        ans1 = 1;
    else
        ans1 = bfs(e1);
    if (s == e2)
        ans2 = 1;
    else
        ans2 = bfs(e2);

    cout << ans1 << '\n';
    cout << ans2 << '\n';
    return 0;
}