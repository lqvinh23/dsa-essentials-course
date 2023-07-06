#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a(25, vector<int>(25));
vector<vector<bool>> visited(25, vector<bool>(25, false));
vector<int> dx{0, 0, 1, -1};
vector<int> dy{-1, 1, 0, 0};
vector<int> rocks(11, 0);

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

bool isValid(Point p)
{
    if (p.x <= 0 || p.y <= 0 || p.x > n || p.y > n)
    {
        return false;
    }
    return true;
}

void reset()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            visited[i][j] = false;
        }
    }
}

void bfs(int s1, int s2, int level)
{
    visited[s1][s2] = true;
    queue<Point> q;
    q.push(Point(s1, s2));
    while (!q.empty())
    {
        Point curPoint = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++)
        {
            Point newPoint(curPoint.x + dx[i], curPoint.y + dy[i]);
            if (isValid(newPoint) && a[newPoint.x][newPoint.y] > level && visited[newPoint.x][newPoint.y] == false)
            {
                visited[newPoint.x][newPoint.y] = true;
                q.push(newPoint);
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int level = 1; level <= 10; level++)
    {
        reset();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (visited[i][j] == false && a[i][j] > level)
                {
                    rocks[level]++;
                    bfs(i, j, level);
                }
            }
        }
    }
    int maxRock = 0;
    for (int level = 1; level <= 10; level++)
    {
        maxRock = max(maxRock, rocks[level]);
    }

    for (int level = 1; level <= 10; level++)
    {
        if (rocks[level] == maxRock)
        {
            cout << level;
            return 0;
        }
    }
    return 0;
}