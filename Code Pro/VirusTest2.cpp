#include <bits/stdc++.h>
using namespace std;

int N;             // Number of executable code data
int M;             // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10];    // Virus data

int sol; // Correct answer

void InputData(void)
{
    int i;

    cin >> N >> M;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < M; i++)
    {
        cin >> B[i];
    }
}

void OutputData(void)
{
    cout << sol << endl;
}

int Find(int start, int d)
{
    int i;

    for (i = 0; i < M; i++)
    {
        if (B[i] - A[start + i] != d)
            return 0;
    }
    return 1;
}

void Solve(void)
{
    int i;
    sort(B, B + M);
    do
    {
        for (i = 0; i <= N - M; i++)
        {
            int d = B[0] - A[i];
            sol += Find(i, d);
        }
    } while (next_permutation(B, B + M));
}

int main(void)
{
    InputData(); // Input

    Solve(); // Problem solving

    OutputData(); // Output

    return 0;
}
