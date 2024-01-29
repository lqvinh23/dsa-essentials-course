#include <bits/stdc++.h>
using namespace std;

int n;
int d[1005] = {0};
int ans = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d, d+n);
    int i = 0;
    while (i < n) {
        ans++;
        int sum = 0;
        do {
            sum = sum + 1;
            i++;
        }
        while (sum <= d[i]);
    }

    cout << ans;
    return 0;
}