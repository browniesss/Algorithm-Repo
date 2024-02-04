#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	char a[10001], b[10001];

	cin >> a >> b;
	long long int idx1 = 0, idx2 = 0, sum = 0;
	while (a[idx1] >= '0' && a[idx1] <= '9')
	{
		int val = a[idx1++] - '0';
		idx2 = 0;

		while (b[idx2] >= '0' && b[idx2] <= '9')
		{
			int val2 = b[idx2++] - '0';
			sum += val * val2;
		}
	}

	cout << sum;
}