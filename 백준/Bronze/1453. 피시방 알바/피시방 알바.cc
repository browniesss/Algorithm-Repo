#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, val, sum = 0;
	int arr[101] = { 0, };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> val;

		if (arr[val] == 0)
		{
			arr[val]++;
		}
		else
		{
			sum++;
		}
	}

	cout << sum;

	return 0;
}