#include <bits/stdc++.h>
using namespace std;

int n;
int x[100005];
int ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x+n);
    int i = 0;
    while (i < n) {
        ans++;
        i = i + x[i];
    }

    cout << ans;

    return 0;
}