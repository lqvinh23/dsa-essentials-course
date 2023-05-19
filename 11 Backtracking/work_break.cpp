#include <bits/stdc++.h>
using namespace std;

bool checkDictionary(string subStr, vector<string> &dictionary)
{
    for (auto word : dictionary)
    {
        if (subStr == word)
            return true;
    }

    return false;
}

bool breakWord(string str, vector<string> &dictionary, vector<string> &output, int length, int &cnt, int i)
{
    // base case
    if (i == length)
    {
        cnt++;
        for (auto word : output)
        {
            cout << word << " ";
        }
        cout << endl;

        // output.clear();
        return true;
    }

    // rec case
    string subStr;
    for (int j = 1; j <= length - i; j++)
    {
        subStr = str.substr(i, j);
        if (checkDictionary(subStr, dictionary))
        {
            output.push_back(subStr);
            breakWord(str, dictionary, output, length, cnt, i + j);
            output.pop_back();
        }
    }
    return false;
}

int main()
{
    string str = "pineapplepenapple";
    vector<string> dictionary = {"apple", "pen", "applepen", "pine", "pineapple"};
    int cnt = 0;
    vector<string> output;
    int length = str.size();
    breakWord(str, dictionary, output, length, cnt, 0);
    cout << cnt;
}