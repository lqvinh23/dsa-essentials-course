#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> a(105, vector<int>(105, 0));
bool *visited = new bool[105];

// Danh dau tat ca nhung dinh cos the di den tu s
void bfs(int s)
{
    visited[s] = true;
    queue<int> que;
    // them s vao queue
    que.push(s);
    // Duyet qua queue
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        // duyet qua nhung dinh ke voi u
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && visited[v] == false)
            {
                que.push(v);
                visited[v] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    // Khoi tao: Danh dau tat ca cac dinh chua duoc tham
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    int cnt = 0;
    // Duyet tung dinh
    for (int i = 1; i <= n; i++)
    {
        // Dinh do chua duoc tham
        if (visited[i] == false)
        {
            bfs(i);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}