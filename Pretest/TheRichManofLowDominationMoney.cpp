#include <bits/stdc++.h>
using namespace std;
int bills[10];
int bill = 0;
int numOfBill = 0;
int moneys[10] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500};
int amount = 0;

int find(int k, int i)
{
    // base case
    if (amount == bill)
    {
        return numOfBill;
    }
    if (amount > bill)
    {
        return 0;
    }

    // recursive case
    if (i <= bills[k])
    {
        amount += moneys[k];
        numOfBill += 1;
        if (find(k, i + 1))
        {
            amount -= moneys[k];
            numOfBill -= 1;
        }
    }

    return find(k + 1, 1);
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        cin >> bills[i];
    }
    cin >> bill;
    bill = bill / 1000;
    cout << find(1, 1);
    return 0;
}