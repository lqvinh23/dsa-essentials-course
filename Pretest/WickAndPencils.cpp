#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int A[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> A[i];
//     }
//     int ans = 0;
//     sort(A, A + n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << A[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < n - 2; i++)
//     {
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 if (A[i] + A[j] > A[k])
//                 {
//                     // cout << A[i] << A[j] << A[k] << endl;
//                     ans++;
//                 }
//                 else
//                     break;
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }

int triangleNumber(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;
    sort(nums.begin(), nums.end());

    int count = 0;
    for (int i = 2; i < n; i++)
    {
        int s = 0;
        int e = i - 1;
        while (s < e)
        {
            if (nums[s] + nums[e] > nums[i])
            {
                count += e - s;
                e--;
            }
            else
                s++;
        }
    }
    return count;
}

// Driver code
int main()
{
    int n;
    cin >> n;
    vector<int> A(50000);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // Function call
    cout << triangleNumber(A);
}