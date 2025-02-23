#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, t, p;
	int tshirtSum = 0;
	int penSum = 0;
	int arr[6] = { 0, };

	cin >> n;

	for (int i = 0; i < 6; i++)
	{
		int num;
		cin >> num;

		arr[i] = num;
	}

	cin >> t >> p;

	for (int i = 0; i < 6; i++)
	{
		int val = arr[i];

		if (val <= 0)
			continue;

		tshirtSum += val % t > 0 ? val / t + 1 : val / t;
	}

	cout << tshirtSum << '\n' << n / p << " " << n % p << '\n';

	return 0;
}