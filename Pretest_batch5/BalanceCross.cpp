#include <bits/stdc++.h>
using namespace std;

int n;
int board[105][105];

int balanceline(int arr[], int N, int i){
    int maxLen = (i < (N - i - 1)) ? i : (N - i - 1);
    for(int len = 1; len <= maxLen; len++){
        int totalSum = 0;
        for(int k = i - len; k <= i + len; ++k){
            totalSum += arr[k];
        }
        if(arr[i] * 3 == totalSum){
            return len;
        }
    }
    return -1;
}

// int balanceCross() {
//     int cnt = 0;
//     for (int i = 1; i < n - 1; i++) {
//         int maxLenVer = (i < (n - i - 1)) ? i : (n - i - 1);
//         for (int j = 1; j < n -1; j++) {
//             int maxLenHor = (j < (n - j - 1)) ? j : (n - j - 1);
//             // int maxLenHor = maxLenVer;
//             for(int lenH = 1; lenH <= maxLenHor; ++lenH) {
//                 int totalSumH = 0;
//                 for(int k = j - lenH; k <= j + lenH; ++k){
//                     totalSumH += board[i][k];
//                 }
//                 if(board[i][j] * 3 == totalSumH){
//                     for (int lenV = 1; lenV <= maxLenVer; ++lenV) {
//                         int totalSumV = 0;
//                         for(int x = i - lenV; x <= i + lenV; ++x){
//                             totalSumV += board[x][j];
//                         }
//                         if (board[i][j] * 3 == totalSumV) {
//                             cnt++;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return cnt;
// }


int balanceCross() {
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        int vertical[105];
        for (int j = 1; j < n - 1; j++)
        {
            for (int k = 0; k < n; k++) {
                vertical[k] = board[k][j];
            }
            int v = balanceline(board[i], n, j);
            int h = balanceline(vertical, n, i);
            if (v == h && v != -1) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    if (n < 3) {
        cout << 0;
        return 0;
    }

    cout << balanceCross();
    
    return 0;
}