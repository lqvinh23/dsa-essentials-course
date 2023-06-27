#include <iostream>
#include <algorithm>

using namespace std;

void encode(int arr[], int n) //{1, 5, 9, 4, 6, 0, 8, 3};
{
    bool mask[n] = {false}; // assign all member to false
    bool cont = true;
    int idx = n / 2;
    while (cont)
    {
        if (!mask[idx])
        {
            cout << arr[idx] << " ";
            mask[idx] = true;
            continue;
        }
        idx *= 2;
        idx %= n;
        for (int i = 0; i < n; ++i)
        {
            if (mask[idx])
            {
                ++idx;
                idx %= n;
            }
            else
            {
                cont = true;
                break;
            }
            cont = false;
        }
    }
}

void decode(int arr[], int n)
{
    bool mask[n] = {false}; // assign all member to false
    bool cont = true;
    int idx = n / 2;
    int rs[n];
    int cur = 0;
    while (cont)
    {
        if (!mask[idx])
        {
            rs[idx] = arr[cur];
            ++cur;
            mask[idx] = true;
            continue;
        }

        idx *= 2;
        idx %= n;
        for (int j = 0; j < n; ++j)
        {
            if (mask[idx])
            {
                ++idx;
                idx %= n;
            }
            else
            {
                cont = true;
                break;
            }
            cont = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << rs[i] << " ";
    }
}

int main()
{
    int arrA[8] = {1, 5, 9, 4, 6, 0, 8, 3};
    cout << "Encoded array: ";
    encode(arrA, 8);
    cout << endl;

    int arrB[8] = {6, 1, 5, 9, 0, 4, 8, 3};
    cout << "Decoded array: ";
    decode(arrB, 8);
    cout << endl;

    return 0;
}