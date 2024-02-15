#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int sum = 0, arr[10] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 10; i++)
	{
		if (sum + arr[i] < 100)
		{
			sum += arr[i];
		}
		else
		{
			int val1 = 100 - sum;
			int val2 = (sum + arr[i]) - 100;

			if (val1 >= val2)
			{
				sum = (sum + arr[i]);
			}

			cout << sum;
			return 0;
		}
	}

	cout << sum;

	return 0;
}