#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> a(255, vector<int>(255, 0));
vector<vector<bool>> visited(255, vector<bool>(255, false));

vector<int> dx{0, 0, -1, 1};
vector<int> dy{-1, 1, 0, 0};

vector<int> D(100005, 0);

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

// Danh dau tat ca nhung dinh cos the di den tu s
void bfs(int s1, int s2)
{
    int size = 1;
    visited[s1][s2] = true;
    queue<Point> que;
    // them s vao queue
    que.push(Point(s1, s2));
    // Duyet qua queue
    while (!que.empty())
    {
        Point curPoint = que.front();
        que.pop();
        // duyet qua nhung dinh ke voi u
        for (int i = 0; i <= 3; i++)
        {
            Point newPoint(curPoint.x + dx[i], curPoint.y + dy[i]);
            if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false && a[newPoint.x][newPoint.y] == 1)
            {
                visited[newPoint.x][newPoint.y] = true;
                que.push(newPoint);
                size++;
            }
        }
    }
    D[size]++;
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visited[i][j] == false && a[i][j] == 1)
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    for (int i = 1; i < D.size(); i++)
    {
        if (D[i] > 0)
            cout << i << " " << D[i] << endl;
    }
    return 0;
}