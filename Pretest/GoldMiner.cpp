#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int m, n;
int golds;
int cnt;
int ans = 10000000;
vector<vector<char>> a(105, vector<char>(105, 0));
vector<vector<bool>> visited(105, vector<bool>(105, false));
vector<int> dx{0, 0, -1, 1};
vector<int> dy{-1, 1, 0, 0};
vector<vector<int>> dist(105, vector<int>(105, 0));

class Point
{
public:
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool isValid(Point point)
{
    if (point.x <= 0 || point.y <= 0 || point.x > n || point.y > m)
    {
        return false;
    }
    return true;
}

int bfs(int s1, int s2)
{
    int timeCnt = 0;
    visited[s1][s2] = true;
    a[s1][s2] = '1';
    dist[s1][s2] = 0;
    queue<Point> que;
    // them s vao queue
    que.push(Point(s1, s2));
    // Duyet qua queue
    while ((!que.empty()) && (cnt < golds))
    {
        Point curPoint = que.front();
        que.pop();
        // duyet qua nhung dinh ke voi u
        if (a[curPoint.x][curPoint.y] >= '1' && a[curPoint.x][curPoint.y] <= '5')
        {
            int energy = a[curPoint.x][curPoint.y] - '0';
            for (int i = -energy; i <= energy; i++)
            {
                for (int j = -energy; j <= energy; j++)
                {
                    // if (i == 0 && j == 0)
                    //     continue;
                    Point newPoint(curPoint.x + i, curPoint.y + j);
                    if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false)
                    {
                        visited[newPoint.x][newPoint.y] = true;
                        dist[newPoint.x][newPoint.y] = dist[curPoint.x][curPoint.y] + 1;
                        que.push(newPoint);
                        if (a[newPoint.x][newPoint.y] == 'G')
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        if (a[curPoint.x][curPoint.y] == '.' || a[curPoint.x][curPoint.y] == 'G')
        {
            for (int i = 0; i <= 3; i++)
            {
                Point newPoint(curPoint.x + dx[i], curPoint.y + dy[i]);
                if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false)
                {
                    visited[newPoint.x][newPoint.y] = true;
                    dist[newPoint.x][newPoint.y] = dist[curPoint.x][curPoint.y] + 1;
                    que.push(newPoint);
                    if (a[newPoint.x][newPoint.y] == 'G')
                    {
                        cnt++;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            timeCnt = max(dist[i][j], timeCnt);
        }
    }

    return timeCnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'G')
            {
                golds++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '.')
            {
                cout << i << " " << j << ": ";
                // Khoi tao: Danh dau tat ca cac dinh chua duoc tham
                for (int u = 1; u <= n; u++)
                {
                    for (int v = 1; v <= m; v++)
                    {
                        visited[u][v] = false;
                    }
                }

                for (int u = 1; u <= n; u++)
                {
                    for (int v = 1; v <= m; v++)
                    {
                        dist[u][v] = 0;
                    }
                }

                cnt = 0;
                int tmpAns = bfs(i, j);
                a[i][j] = '.';
                cout << tmpAns << endl;
                ans = min(tmpAns, ans);
            }
        }
    }

    // cout << bfs(5, 5) << endl;
    // for (int u = 1; u <= n; u++)
    // {
    //     for (int v = 1; v <= m; v++)
    //     {
    //         cout << dist[u][v] << " ";
    //     }
    //     cout << endl;
    // }
    // if (ans == 10000000)
    // {
    //     ans = -1;
    // }
    cout << ans;

    return 0;
}