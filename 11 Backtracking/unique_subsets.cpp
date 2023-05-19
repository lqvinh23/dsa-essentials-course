#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void print()
{
    for (auto a : ans)
    {
        if (a.empty())
        {
            cout << "NULL";
        }
        for (auto r : a)
        {
            cout << r << " ";
        }
        cout << endl;
    }
}

void find(vector<int> nums, vector<int> &res, int n, int i)
{
    // base case
    if (i == n)
    {
        ans.push_back(res);
        return;
    }

    // recursive case
    res.push_back(nums[i]);
    find(nums, res, n, i + 1);
    res.pop_back();
    find(nums, res, n, i + 1);
    return;
}

void unify(int n)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == ans[i - 1])
        {
            ans.erase(ans.begin() + i);
            i--;
        }
    }
}

int main()
{
    // vector<int> nums = {0, 1, 1, 1, 4, 5, 4, 4, 2};
    vector<int> nums = {1, 4, 4, 4, 4};
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> res;
    find(nums, res, n, 0);
    sort(ans.begin(), ans.end());
    unify(n);
    print();
    return 0;
}