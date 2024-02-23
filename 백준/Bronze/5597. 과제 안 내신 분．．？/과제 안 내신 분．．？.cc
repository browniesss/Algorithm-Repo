#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	int arr[30] = { 0, };

	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		arr[n - 1]++;
	}

	for (int i = 0; i < 30; i++)
	{
		if (arr[i] == 0)
		{
			cout << i + 1 << endl;
		}
	}

	return 0;
}