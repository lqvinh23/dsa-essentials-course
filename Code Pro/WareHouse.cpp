#include <bits/stdc++.h>
using namespace std;
int n, m;
int oo = (int)1e9;
vector<vector<int>> edges(10005, vector<int>(3));
vector<vector<int>> minPath(105, vector<int>(105, oo));
vector<int> dist(105);

class Point
{
public:
    int x, d;
    Point(int x, int d)
    {
        this->x = x;
        this->d = d;
    }
};

class Compare
{
public:
    bool operator()(Point a, Point b)
    {
        if (a.d > b.d)
            return true;
        return false;
    }
};

void dijk(int s)
{
    for (int i = 1; i <= n; i++)
        dist[i] = oo;
    priority_queue<Point, vector<Point>, Compare> pq;
    pq.push(Point(s, 0));
    dist[s] = 0;

    while (!pq.empty())
    {
        Point curPoint = pq.top();
        pq.pop();
        for (int i = 1; i <= m; i++)
        {
            if (edges[i][0] == curPoint.x || edges[i][1] == curPoint.x)
            {
                int newId;
                if (edges[i][0] == curPoint.x)
                    newId = edges[i][1];
                else
                    newId = edges[i][0];
                Point newPoint(newId, edges[i][2] + curPoint.d);
                if (dist[newPoint.x] > newPoint.d)
                {
                    dist[newPoint.x] = newPoint.d;
                    pq.push(newPoint);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
        minPath[s][i] = minPath[i][s] = dist[i];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> edges[i][0];
        cin >> edges[i][1];
        cin >> edges[i][2];
    }

    for (int i = 1; i <= n; i++)
    {
        dijk(i);
    }
    int ans = oo;
    for (int i = 1; i <= n; i++)
    {
        int maxRow = 0;
        for (int j = 1; j <= n; j++)
        {
            maxRow = max(maxRow, minPath[i][j]);
        }
        ans = min(ans, maxRow);
    }

    cout << ans;
    return 0;
}