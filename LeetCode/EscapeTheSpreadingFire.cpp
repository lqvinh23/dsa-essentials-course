#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int m, n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool visited[305][305];
int dist[305][305];
int distFire[305][305];
int minFire = 0;
int minPerson = 0;

class Point {
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
queue<Point> q;

bool isValid(Point p) {
    if (p.x >= m || p.y >= n || p.x < 0 || p.y < 0) return false;
    return true;
}

int bfsPerson(vector<vector<int>> board) {
    visited[0][0] = true;
    dist[0][0] = 0;
    q.push(Point(0, 0));
    while (!q.empty()) {
        Point curPoint = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++) {
            Point newPoint(curPoint.x + dx[i], curPoint.y + dy[i]);
            if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false && board[newPoint.x][newPoint.y] == 0) {
                q.push(newPoint);
                visited[newPoint.x][newPoint.y] = true;
                dist[newPoint.x][newPoint.y] = dist[curPoint.x][curPoint.y] + 1;
            }
        }
    }
    return dist[m-1][n-1];
}

int bfsFire(vector<vector<int>> board) {
    while (!q.empty()) {
        Point curPoint = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++) {
            Point newPoint(curPoint.x + dx[i], curPoint.y + dy[i]);
            if (isValid(newPoint) && visited[newPoint.x][newPoint.y] == false && board[newPoint.x][newPoint.y] == 0) {
                q.push(newPoint);
                visited[newPoint.x][newPoint.y] = true;
                distFire[newPoint.x][newPoint.y] = distFire[curPoint.x][curPoint.y] + 1;
            }
        }
    }
    return distFire[m-1][n-1];
}

int maximumMinutes(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
            dist[i][j] = INT_MAX;
        }
    }

    minPerson = bfsPerson(grid);
    if (minPerson == INT_MAX) return -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
            distFire[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                q.push(Point(i, j));
                visited[i][j] = true;
                distFire[i][j] = 0;
            }
        }
    }
    minFire = bfsFire(grid);
    if (minFire == INT_MAX) return 1000000000;

    if (minFire < minPerson) return -1;

    int diff = minFire-minPerson;
    if(dist[m-2][n-1]!=INT_MAX && dist[m-1][n-2]!=INT_MAX && ((distFire[m-2][n-1]-dist[m-2][n-1])>diff || (distFire[m-1][n-2]-dist[m-1][n-2]>diff))){
        return diff;
    }

    return diff-1;
}


int main() {
    vector<vector<int>> grid = {{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};

    int result = maximumMinutes(grid);
    cout << "Maximum Minutes: " << result << endl;

    return 0;
}