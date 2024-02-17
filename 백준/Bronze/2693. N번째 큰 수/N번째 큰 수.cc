#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	int arr[10] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			int val;
			cin >> val;

			arr[k] = val;
		}

		sort(arr, arr + 10);

		cout << arr[7] << endl;
	}

	return 0;
}