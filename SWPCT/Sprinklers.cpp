#include <bits/stdc++.h>
using namespace std;

int n, l1, k;
// int x[100005];
vector<int> x;

int main() {
    cin >> n >> l1 >> k;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        x.push_back(tmp);
    }

    // sort(x, x+n);
    sort(x.begin(), x.end());

    // for (int i = 0; i < n; i++)
    // {
    //     cout << x[i] << " ";
    // }
    // cout << endl;

    int l = x[0];
    int r = x[n-1];

    int v_min = 0;
    int v_max = max((l + r - k + 1) / 2 - l, r - ((l + r - k + 1) / 2));
    // cout << l << " " << r << " " << v_min << " " << v_max << endl;
    int ans = v_max;

    while (v_min <= v_max) {
        int v = (v_min + v_max) / 2;
        int i = 0;
        int j = 0;
        int k_pos[k] = {0};
        while (i < n && j < k) {
            k_pos[j] = x[i] + v;
            i = upper_bound(x.begin(), x.end(), k_pos[j]+v) - x.begin();
            j++;
        }
        if (i >= n) {
            ans = v;
            v_max = v-1;
        } else {
            v_min = v+1;
        }
    }

    cout << ans;

    return 0;
}