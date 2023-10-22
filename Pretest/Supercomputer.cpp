#include <bits/stdc++.h>
using namespace std;

////@one testcase////////////////////////////
// int t, n;
// int h[100005], d[100005];
// int c[100005];
// struct job
// {
//     int h;
//     int d;
// } jobs[100005];
// int late = 1e9;

// bool cmp(job a, job b)
// {
//     if (a.d < b.d)
//         return true;
//     return false;
// }

// int main()
// {
//     cin >> n;
//     int max_h = 0;
//     int max_h_idx = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> h[i];
//         // max_h = max(max_h, h[i]);
//         // if (max_h == h[i])
//         //     max_h_idx = i;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> d[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         jobs[i].h = h[i];
//         jobs[i].d = d[i];
//     }

//     // jobs[max_h_idx].h = 1;

//     sort(jobs, jobs + n, cmp);

//     for (int i = 0; i < n; i++)
//     {
//         cout << jobs[i].h << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << jobs[i].d << " ";
//     }
//     cout << endl;

//     for (int j = 0; j < n; j++)
//     {
//         int tmp = jobs[j].h;
//         jobs[j].h = 1;
//         int tmp_late = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (i == 0)
//                 c[i] = jobs[i].h;
//             else
//                 c[i] = c[i - 1] + jobs[i].h;
//             tmp_late = max(tmp_late, c[i] - jobs[i].d);
//         }
//         jobs[j].h = tmp;
//         late = min(late, tmp_late);
//     }

//     cout << late;
//     return 0;
// }

/// @multi testcases ////////////////////////////////
int t;
int n[15];
int h[15][100005];
int d[15][100005];
struct job
{
    int h;
    int d;
};
long long late[15] = {1000000000};

bool cmp(job a, job b)
{
    if (a.d < b.d)
        return true;
    return false;
}

int main()
{
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        job jobs[100005] = {0};
        long long c[100005] = {0};
        int max_h = 0;
        int max_h_idx = 0;
        cin >> n[k];
        for (int i = 0; i < n[k]; i++)
        {
            cin >> h[k][i];
            max_h = max(max_h, h[k][i]);
            if (max_h == h[k][i])
                max_h_idx = i;
        }
        for (int i = 0; i < n[k]; i++)
        {
            cin >> d[k][i];
        }

        for (int i = 0; i < n[k]; i++)
        {
            jobs[i].h = h[k][i];
            jobs[i].d = d[k][i];
        }

        sort(jobs, jobs + n[k], cmp);

        // if (false) {
        if (n[k] >= 50000)
        {
            jobs[max_h_idx].h = 1;
            long long tmp = 0;
            for (int i = 0; i < n[k]; i++)
            {
                if (i == 0)
                    c[i] = jobs[i].h;
                else
                    c[i] = c[i - 1] + jobs[i].h;
                tmp = max(tmp, c[i] - jobs[i].d);
            }
            late[k] = tmp;
        }
        else
        {
            long long late_min = 1000000000;
            for (int j = 0; j < n[k]; j++)
            {
                if (jobs[j].h < (max_h / 2))
                    continue;
                int tmp = jobs[j].h;
                jobs[j].h = 1;
                long long tmp_late = 0;
                for (int i = 0; i < n[k]; i++)
                {
                    if (i == 0)
                        c[i] = jobs[i].h;
                    else
                        c[i] = c[i - 1] + jobs[i].h;
                    tmp_late = max(tmp_late, c[i] - jobs[i].d);
                }
                late_min = min(late_min, tmp_late);
                jobs[j].h = tmp;
            }
            late[k] = late_min;
        }
    }

    for (int k = 0; k < t; k++)
    {
        cout << late[k] << endl;
    }
    return 0;
}

/// @Bruteforce ////////////////////////////////
// int t, n;
// int h[100005], d[100005];
// int c[100005];
// class job
// {
// public:
//     int h;
//     int d;
//     bool operator<(const job &other) const
//     {
//         return d < other.d;
//     }
// } jobs[100005];
// int late = 0;

// bool cmp(job a, job b)
// {
//     if (a.d < b.d)
//         return true;
//     return false;
// }

// int main()
// {
//     cin >> n;
//     int max_h = 0;
//     int max_h_idx = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> h[i];
//         max_h = max(max_h, h[i]);
//         if (max_h == h[i])
//             max_h_idx = i;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> d[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         jobs[i].h = h[i];
//         jobs[i].d = d[i];
//     }

//     // jobs[max_h_idx].h = 1;

//     for (int k = 0; k < n; k++)
//     {
//         int tmp = jobs[k].h;
//         jobs[k].h = 1;
//         do
//         {
//             sort(jobs, jobs + n, cmp);
//             for (int i = 0; i < n; i++)
//             {
//                 cout << jobs[i].h << " ";
//             }
//             cout << endl;
//             for (int i = 0; i < n; i++)
//             {
//                 cout << jobs[i].d << " ";
//             }
//             cout << endl;

//             for (int i = 0; i < n; i++)
//             {
//                 if (i == 0)
//                     c[i] = jobs[i].h;
//                 else
//                     c[i] = c[i - 1] + jobs[i].h;
//                 late = max(late, c[i] - jobs[i].d);
//             }

//             cout << late << endl;
//         } while (next_permutation(jobs, jobs + n));
//         jobs[k].h = tmp;
//     }
//     return 0;
// }
