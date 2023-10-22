#include <bits/stdc++.h>
using namespace std;

int n, x, y, z;
int d[10005];
bool visited[10005];
int dist[10005];
int ans = -1;
int oo = INT_MAX;

bool isDivisible(int a, int b) {
    if (a%b == 0 || b%a == 0) return true;
    return false;
}

bool isOddEven(int a, int b) {
    if (a%2 == 0 && b%2 != 0) return true;
    if (a%2 != 0 && b%2 == 0) return true;
    return false;
}

int bfs(int s, int e) {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = -1;
    }
    visited[s] = true;
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (visited[i]==false && isDivisible(d[cur],d[i]) && isOddEven(d[cur],d[i])) {
                visited[i] = true;
                dist[i] = dist[cur] + 1;
                // cout << d[i] << " " << dist[i] << endl;
                q.push(i);
                if (i == e) return dist[i];
            }
        }
    }
    return dist[e];
}

int main() {
    cin >> n >> x >> y >> z;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    int xy = bfs(x, y);
    // cout << "xy" << " " << xy << endl;
    if (xy == -1 ) {
        cout << -1;
        return 0;
    }
    int yz = bfs(y, z);
    // cout << "yz" << " " << yz << endl;
    if (yz == -1 ) {
        cout << -1;
        return 0;
    }

    ans = xy + yz;
    cout << ans;

    return 0;
}