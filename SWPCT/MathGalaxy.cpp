#include <bits/stdc++.h>
using namespace std;

int s, e1, e2;
int ans1, ans2;
bool visited[10005] = {false};
int d[8] = {1000, -1000, 100, -100, 10, -10, 1, -1};
int dist[10005] = {0};

void InputData()
{
    cin >> s >> e1 >> e2;
}

int numOfFactors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;
 
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

bool oneDiffNum(int curE, int newE) {
    int numOfDiff = 0;
    int curNum[4] = {curE/1000, (curE%1000)/100, ((curE%1000)%100)/10, curE%10};
    int newNum[4] = {newE/1000, (newE%1000)/100, ((newE%1000)%100)/10, newE%10};
    for (int i = 0; i < 4; i++) {
        if (curNum[i] != newNum[i]) numOfDiff++;
    }
    if (numOfDiff != 1) {
        return false;
    }
    return true;
}

bool isValid(int curE, int newE)
{
    if (newE >= 10000 || newE < 1000 || oneDiffNum(curE, newE) == false || abs(numOfFactors(curE) - numOfFactors(newE)) > 1)
        return false;
    return true;
}

int bfs(int e)
{
    for (int i = 1000; i <= 9999; i++)
    {
        visited[i] = false;
    }
    for (int i = 1000; i <= 9999; i++)
    {
        dist[i] = -1;
    }
    visited[s] = true;
    dist[s] = 0;
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
                    if (newE == e) return dist[e];
                }
            }
        }
    }
    return dist[e];
}

int main()
{
    InputData();

    if (s == e1)
        ans1 = 0;
    else
        ans1 = bfs(e1);
    if (s == e2)
        ans2 = 0;
    else
        ans2 = bfs(e2);

    cout << ans1 << " " << ans2;

    return 0;
}