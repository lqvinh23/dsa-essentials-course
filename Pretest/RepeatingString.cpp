#include <bits/stdc++.h>
using namespace std;

// C++: To check if the string inp is a substring of the string S
bool isSubstring(string inp)
{
    int size = inp.size();
    for (int i = 0; i < size; i++)
    {
        if (inp[i] != 'a' && inp[i] != 'b' && inp[i] != 'c')
            return false;
    }
    if (size > 2)
    {
        for (int i = 0; i < size - 2; i++)
        {
            if (inp[i] == 'a' && inp[i + 1] != 'b')
                return false;
            if (inp[i] == 'a' && inp[i + 1] == 'b' && inp[i + 2] != 'c')
                return false;

            if (inp[i] == 'b' && inp[i + 1] != 'c')
                return false;
            if (inp[i] == 'b' && inp[i + 1] == 'c' && inp[i + 2] != 'a')
                return false;

            if (inp[i] == 'c' && inp[i + 1] != 'a')
                return false;
            if (inp[i] == 'c' && inp[i + 1] == 'a' && inp[i + 2] != 'b')
                return false;
        }
    }

    if (size == 2)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (inp[i] == 'a' && inp[i + 1] == 'c')
                return false;
            if (inp[i] == 'b' && inp[i + 1] == 'a')
                return false;
            if (inp[i] == 'c' && inp[i + 1] == 'b')
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    string strArr[105];
    for (int i = 0; i < n; i++)
    {
        cin >> strArr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (isSubstring(strArr[i]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
