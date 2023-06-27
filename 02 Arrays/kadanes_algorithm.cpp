#include <iostream>
using namespace std;

int maximum_subarray_sum(int arr[], int n)
{

	int cs = 0;
	int largest = 0;

	for (int i = 0; i < n; i++)
	{
		cs = cs + arr[i];
		if (cs < 0)
		{
			cs = 0;
		}
		largest = max(largest, cs);
	}

	return largest;
}

void Kadane_Algorithms(int arr[], int n)
{
	int cs = 0, ls = 0;
	int max_element = (-2147483648);
	bool check = 1;
	for (int i = 0; i < n; i++)
	{
		cs = cs + arr[i];
		if (cs < 0)
		{
			cs = 0;
		}
		ls = max(ls, cs);
		if (arr[i] >= 0)
		{
			check = 0;
		}

		if (arr[i] > max_element)
			max_element = arr[i];
	}

	if (check)
	{
		cout << max_element << endl;
	}
	else
	{
		cout << ls << endl;
	}

	// Time Complexity : O(N).
}

int main()
{
	// Array Containing
	int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
	int n = sizeof(arr) / sizeof(int);

	cout << maximum_subarray_sum(arr, n) << endl;
	Kadane_Algorithms(arr, n);

	return 0;
}