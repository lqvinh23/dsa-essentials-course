#include <iostream>
using namespace std;

int bills[10];
int bill = 0;
int ans = -1;
int moneys[10] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500};
int amount = 0;

void find(int i, int numOfBill)
{
    if (i > 9)
    {
        return;
    }

    for (int n = bills[i]; n >= 0; n--)
    {
        numOfBill += n;
        amount += (n * moneys[i]);
        // int left = bill - amount;
        // if (left != 0 && bills[i + 1] > 0 && i < 9)
        //     if ((left / moneys[i + 1]) <= (ans - numOfBill))
        //     {
        //         amount -= (n * moneys[i]);
        //         numOfBill -= n;
        //         continue;
        //     }
        if (amount <= bill)
        {
            if (amount == bill) {
                ans = max(ans, numOfBill);
            }
            else {
                find(i + 1, numOfBill);
            }
        }
        amount -= (n * moneys[i]);
        numOfBill -= n;
    }
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        cin >> bills[i];
    }
    cin >> bill;
    bill = bill/1000;
    find(1, 0);
    cout << ans;
    return 0;
}

////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// int bills[10];
// int bill = 0;
// int numOfBill = -1;
// int moneys[10] = {0, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};
// int amount = 0;
// int pay[10] = {0};

// void find(int i)
// {
//     if (i > 9)
//     {
//         return;
//     }

//     for (int n = bills[i]; n >= 0; n--)
//     {
//         pay[i] = n;
//         amount += (n * moneys[i]);
//         if (amount <= bill)
//         {
//             if (amount == bill)
//             {
//                 int tmp = 0;
//                 for (int k = 1; k <= 9; k++)
//                 {
//                     cout << pay[k] << " ";
//                     tmp += pay[k];
//                 }
//                 cout << endl;
//                 numOfBill = max(numOfBill, tmp);
//             }
//             else
//                 find(i + 1);
//         }
//         amount -= (n * moneys[i]);
//         pay[i] = 0;
//     }
// }

// int main()
// {
//     for (int i = 1; i <= 9; i++)
//     {
//         cin >> bills[i];
//     }
//     cin >> bill;
//     find(1);
//     cout << numOfBill;
//     return 0;
// }