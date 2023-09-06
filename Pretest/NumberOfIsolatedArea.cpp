#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[105][105];
bool visited[105][105];
int ans = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

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
    if (p.x > n || p.x <= 0 || p.y > m || p.y <= 0)
    {
        return false;
    }
    return true;
}

bool bfs(int s1, int s2)
{
    bool ret = true;
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
            if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false && board[newPoint.x][newPoint.y] == 0)
            {
                if (newPoint.x == 1 || newPoint.x == n || newPoint.y == 1 || newPoint.y == m)
                    ret = false;
                q.push(newPoint);
                visited[newPoint.x][newPoint.y] = true;
            }
        }
    }

    return ret;
}

void reset()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            visited[i][j] = false;
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            if (board[i][j] == 0 && visited[i][j] == false)
            {
                cout << i << j << " ";
                if (bfs(i, j))
                {
                    ans++;
                }
                cout << ans << endl;
            }
        }
    }

    cout << ans;
    return 0;
}