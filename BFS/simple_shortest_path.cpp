#include <bits/stdc++.h>
#include <string>
using namespace std;

int m, n;
vector<vector<char>> a(255, vector<char>(255, 0));
vector<vector<bool>> visited(255, vector<bool>(255, false));
int s1, s2, d1, d2;
int oo = 1000000000;
vector<vector<int>> dist(255, vector<int>(255, 0));
vector<int> dx{0, 0, -1, 1};
vector<int> dy{-1, 1, 0, 0};
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

void bfs(int s1, int s2)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dist[i][j] = oo;
        }
    }
    dist[s1][s2] = 0;
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
            if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false && a[newPoint.x][newPoint.y] != '+')
            {
                visited[newPoint.x][newPoint.y] = true;
                dist[newPoint.x][newPoint.y] = dist[curPoint.x][curPoint.y] + 1;
                que.push(newPoint);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string tmpString;
        cin >> tmpString;
        tmpString = " " + tmpString;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = tmpString[j];
            if (a[i][j] == 'S')
            {
                s1 = i;
                s2 = j;
            }
            if (a[i][j] == 'D')
            {
                d1 = i;
                d2 = j;
            }
        }
    }

    // Khoi tao: Danh dau tat ca cac dinh chua duoc tham
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            visited[i][j] = false;
        }
    }

    bfs(s1, s2);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    if (dist[d1][d2] == oo)
    {
        cout << "-1";
        return 0;
    }
    cout << dist[d1][d2];
    return 0;
}