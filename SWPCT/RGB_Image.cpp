#include <bits/stdc++.h>
#include <string>
using namespace std;

int n, m;
char color;
int RGBs[3] = {0, 0, 0};
int RGBc[3] = {0, 0, 0};
vector<vector<char>> a(105, vector<char>(105));
vector<vector<bool>> visited(105, vector<bool>(105, false));
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

bool isValid(Point p)
{
    if (p.x > n || p.y > m || p.x <= 0 || p.y <= 0)
    {
        return false;
    }
    return true;
}

void bfs(int s1, int s2)
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
            if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false && a[newPoint.x][newPoint.y] == color)
            {
                visited[newPoint.x][newPoint.y] = true;
                q.push(newPoint);
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
            switch (a[i][j])
            {
            case 'R':
                RGBs[0]++;
                break;
            case 'G':
                RGBs[1]++;
                break;
            case 'B':
                RGBs[2]++;
                break;
            default:
                break;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            color = 'R';
            break;
        case 1:
            color = 'G';
            break;
        case 2:
            color = 'B';
            break;
        default:
            break;
        }

        int cnt = 0;
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= m; v++)
            {
                if (a[u][v] == color && visited[u][v] == false)
                {
                    cnt++;
                    bfs(u, v);
                }
            }
        }
        RGBc[i] = cnt;
    }

    int max = 0;
    for (int i = 0; i < 3; i++)
    {
        if (RGBc[i] > max)
        {
            max = RGBc[i];
        }
    }

    int maxArea = 0;
    for (int i = 0; i < 3; i++)
    {
        if (RGBc[i] == max)
        {
            if (RGBs[i] > maxArea)
            {
                maxArea = RGBs[i];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (RGBc[i] == max)
        {
            if (RGBs[i] == maxArea)
            {
                if (i == 0)
                {
                    cout << 'R';
                    break;
                }
                else if (i == 1)
                {
                    cout << 'G';
                    break;
                }
                else
                {
                    cout << 'B';
                    break;
                }
            }
        }
    }

    return 0;
}