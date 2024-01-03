#include <iostream>

using namespace std;

int arr[1000001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, temp;
	
	arr[0] = 0;
	arr[1] = 1;

	cin >> n;

	temp = n < 0 ? n * -1 : n;

	for (int i = 2; i <= temp; i++)
	{
		arr[i] = arr[i - 1] % 1000000000 + arr[i - 2] % 1000000000;
		arr[i] %= 1000000000;
	}

	if (n < 0 && n % 2 == 0)
	{
		cout << -1 << endl;
	}
	else if (n == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << 1 << endl;
	}

	cout << arr[temp];

	return 0;
}