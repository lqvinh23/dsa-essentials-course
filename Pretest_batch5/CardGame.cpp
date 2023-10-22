#include <bits/stdc++.h>
using namespace std;

int n, x;
int c[100005];
int ans = 1e9;
deque<int> q;


void cardgame(int step, int sum) {
    if (step >= ans) return;
    if (step >= n) return;
    if (sum > x) return;
    if (sum == x) {
        if (step < ans) {
            ans = step; 
        }
        return;
    }

    int tmp1 = q.front();
    q.pop_front();
    cardgame(step + 1, sum + tmp1);
    q.push_front(tmp1);

    int tmp2 = q.back();
    q.pop_back();
    cardgame(step + 1, sum + tmp2);
    q.push_back(tmp2);

    return;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        q.push_back(c[i]);
    }

    cardgame(0, 0);

    if (ans == 1e9) {
        cout << -1;
        return 0;
    }

    cout << ans;

    return 0;
}