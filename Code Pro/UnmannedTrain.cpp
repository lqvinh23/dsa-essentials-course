#include <iostream>
#include <queue>
using namespace std;

int n, m;
int a[55][55] = {0};
bool visited[55][55] = {false};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int dist[55][55] = {0};

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
    if (p.x > n || p.y > m || p.x <= 0 || p.y <= 0)
        return false;
    return true;
}

int bfs(int s1, int s2)
{
    visited[s1][s2] = true;
    queue<Point> q;
    queue<Point> que;
    q.push(Point(s1, s2));
    que.push(Point(s1, s2));
    while (!q.empty())
    {
        Point curPoint = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++)
        {
            Point newPoint(curPoint.x + dx[i], curPoint.y + dy[i]);
            if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false && a[newPoint.x][newPoint.y] == 1)
            {
                visited[newPoint.x][newPoint.y] = true;
                a[newPoint.x][newPoint.y] = 2;
                q.push(newPoint);
                que.push(newPoint);
            }
        }
    }

    while (!que.empty())
    {
        Point curPoint = que.front();
        que.pop();
        for (int i = 0; i <= 3; i++)
        {
            Point newPoint(curPoint.x + dx[i], curPoint.y + dy[i]);
            if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false && a[newPoint.x][newPoint.y] != 2)
            {
                if (a[newPoint.x][newPoint.y] == 1)
                {
                    return dist[curPoint.x][curPoint.y];
                }
                visited[newPoint.x][newPoint.y] = true;
                dist[newPoint.x][newPoint.y] = dist[curPoint.x][curPoint.y] + 1;
                q.push(newPoint);
                que.push(newPoint);
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1 && visited[i][j] == false)
            {
                a[i][j] = 2;
                cout << bfs(i, j);
                return 0;
            }
        }
    }

    return 0;
}