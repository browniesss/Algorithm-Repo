#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, value, count = 0;

	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		if (i % 5 == 0)
		{
			count++;
		}

		if (i % 25 == 0)
		{
			count++;
		}

		if (i % 125 == 0)
		{
			count++;
		}
	}

	cout << count << endl;
	
	return 0;
}