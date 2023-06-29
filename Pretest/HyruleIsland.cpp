#include <bits/stdc++.h>
using namespace std;

int r, c, n;
int ans = INT_MAX;
vector<vector<char>> board(105, vector<char>(105));
vector<vector<bool>> visited(105, vector<bool>(105, false));
vector<vector<int>> dist(10, vector<int>(10, 0));
vector<vector<int>> cnt(105, vector<int>(105, 0));
vector<int> permutation;
vector<vector<int>> permutations;
vector<int> dx{0, 0, -1, 1};
vector<int> dy{-1, 1, 0, 0};
vector<char> digits{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

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
    if (point.x <= 0 || point.y <= 0 || point.x > r || point.y > c)
    {
        return false;
    }
    return true;
}

void bfs(int s1, int s2, int s)
{
    // cout << "Xet " << s << endl;
    cnt[s1][s2] = 0;
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
            if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false && board[newPoint.x][newPoint.y] != '#')
            {
                q.push(newPoint);
                visited[newPoint.x][newPoint.y] = true;
                cnt[newPoint.x][newPoint.y] = cnt[curPoint.x][curPoint.y] + 1;
                for (int k = s + 1; k <= n; k++)
                {
                    if (board[newPoint.x][newPoint.y] == digits[k])
                    {
                        dist[s][k] = cnt[newPoint.x][newPoint.y];
                        dist[k][s] = cnt[newPoint.x][newPoint.y];
                        // cout << s << " to " << k << ": " << dist[s][k] << endl;
                        break;
                    }
                }
            }
        }
    }
}

void genPermutations(int i)
{
    // base case
    if (i == n)
    {
        permutations.push_back(permutation);
        return;
    }
    // recursive
    for (int j = i; j < n; j++)
    {
        swap(permutation[i], permutation[j]);
        genPermutations(i + 1);
        swap(permutation[i], permutation[j]);
    }
}

int main()
{
    cin >> r >> c >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= r; i++)
    {
        string tmpString;
        cin >> tmpString;
        tmpString = " " + tmpString;
        for (int j = 1; j <= c; j++)
        {
            board[i][j] = tmpString[j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u <= r; u++)
        {
            for (int v = 1; v <= c; v++)
            {
                if (board[u][v] == digits[i])
                {
                    // reset(visited);
                    for (int k = 1; k <= r; k++)
                    {
                        for (int j = 1; j <= c; j++)
                        {
                            visited[k][j] = false;
                        }
                    }

                    for (int k = 1; k <= r; k++)
                    {
                        for (int j = 1; j <= c; j++)
                        {
                            cnt[k][j] = 0;
                        }
                    }
                    bfs(u, v, i);
                }
            }
        }
    }

    int blockedCnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == 0)
            {
                blockedCnt++;
            }
            // cout << dist[i][j] << " ";
        }
        if (blockedCnt == n)
        {
            cout << -1;
            return 0;
        }
        else
            blockedCnt = 0;
        // cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        permutation.push_back(i);
    }
    genPermutations(0);
    for (int i = 0; i < permutations.size(); i++)
    {
        int tmpAns = 0;
        for (int j = 0; j < permutations[0].size(); j++)
        {
            // cout << permutations[i][j];
            if (j < permutations[0].size() - 1)
                tmpAns += dist[permutations[i][j]][permutations[i][j + 1]];
        }
        // cout << endl;
        // cout << tmpAns << endl;
        ans = min(ans, tmpAns);
    }

    if (ans == 0)
        ans = -1;
    cout << ans;
    return 0;
}