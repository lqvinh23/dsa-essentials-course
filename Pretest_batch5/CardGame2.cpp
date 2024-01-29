#include <bits/stdc++.h>
using namespace std;

int n, x;
int c[100005];
int ans = 1e9;
int sum = 0;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    // cout << sum << endl;
    int j = 1;
    int i = 1;
    while (i <= n && j <= n) {
        if (sum > x) {
            sum = sum - c[i];
            i++;
        }
        else if (sum < x) {
            sum = sum + c[j];
            j++;
        }
        else {
            ans = min(ans, n-i+j);
            sum = sum + c[j];
            j++;
        }
        // cout << i << " " << j << " " << sum << " " << ans << endl;
    }

    if (ans == 1e9) {
        ans = -1;
    }

    cout << ans;

    return 0;
}