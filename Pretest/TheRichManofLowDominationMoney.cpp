#include <iostream>
using namespace std;

int bills[10];
int bill = 0;
int numOfBill = -1;
int moneys[10] = {0, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};
int amount = 0;
int pay[10] = {0};

void find(int i)
{
    if (i > 9)
    {
        return;
    }

    // if ({branch_and_bound condition})
    //     return;

    for (int n = bills[i]; n >= 0; n--)
    {
        pay[i] = n;
        amount += (n * moneys[i]);
        if (amount <= bill)
        {
            if (amount == bill)
            {
                int tmp = 0;
                for (int k = 1; k <= 9; k++)
                {
                    cout << pay[k] << " ";
                    tmp += pay[k];
                }
                cout << endl;
                numOfBill = max(numOfBill, tmp);
            }
            else
                find(i + 1);
        }
        amount -= (n * moneys[i]);
        pay[i] = 0;
    }
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        cin >> bills[i];
    }
    cin >> bill;
    find(1);
    cout << numOfBill;
    return 0;
}

// #include <iostream>
// using namespace std;

// int bills[10];
// int bill = 0;
// int numOfBill = -1;
// int moneys[10] = {0, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};
// int pay[10] = {0};

// void find(int i, int amount, int numBills)
// {
//     if (i > 9)
//     {
//         if (amount == bill)
//         {
//             numOfBill = max(numOfBill, numBills);
//         }
//         return;
//     }

//     for (int n = bills[i]; n >= 0; n--)
//     {
//         int remainingAmount = amount + n * moneys[i];
//         int remainingBills = numBills + n;
//         if (remainingAmount <= bill && remainingBills > numOfBill)
//         {
//             pay[i] = n;
//             find(i + 1, remainingAmount, remainingBills);
//             pay[i] = 0;
//         }
//     }
// }

// int main()
// {
//     for (int i = 1; i <= 9; i++)
//     {
//         cin >> bills[i];
//     }
//     cin >> bill;
//     find(1, 0, 0);
//     cout << numOfBill;
//     return 0;
// }