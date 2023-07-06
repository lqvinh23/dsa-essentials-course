#include <bits/stdc++.h>
using namespace std;

int N;                     // Number of executable code data
int M;                     // Number of virus data
vector<int> A(20000 + 10); // Executable code data
vector<int> B(10 + 10);    // Virus data
vector<vector<int>> Bs;

int sol = 0; // Correct answer

void InputData(void)
{
    int i;
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    A.resize(N);

    for (i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    B.resize(M);
}

void display(vector<int> B)
{
    for (int i = 0; i < B.size(); i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
}

void FindPermutations(vector<int> B)
{
    sort(B.begin(), B.end());
    do
    {
        display(B);
        Bs.push_back(B);
    } while (next_permutation(B.begin(), B.end()));
}

void OutputData(void)
{
    cout << sol;
}

int Find(int kth, int start, int d)
{
    for (int i = 0; i < M; i++)
    {
        if (Bs[kth][i] != A[start + i] + d)
            return 0;
    }
    return 1;
}

void Solve(void)
{
    for (int k = 0; k < Bs.size(); k++)
    {
        display(Bs[k]);
        for (int i = 0; i <= N - M; i++)
        {
            int d = Bs[k][0] - A[i];
            sol += Find(k, i, d);
        }
        cout << sol << endl;
    }
}

int main(void)
{
    InputData(); // Input
    cout << endl;

    FindPermutations(B);
    cout << endl;

    Solve(); // Problem solving
    cout << endl;

    OutputData(); // Output

    return 0;
}