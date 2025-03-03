#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int min = 0;
	int num;
	vector<int> a;
	vector<int> b;

	cin >> num;
	for (int k = 0; k < 2; k++)
	{
		int val;
		for (int i = 0; i < num; i++)
		{
			cin >> val;
			if (k == 0)
				a.push_back(val);
			else
				b.push_back(val);
		}
	}

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	for (int i = 0; i < num; i++)
	{
		min += a[i] * b[i];
	}

	cout << min << '\n';

	return 0;
}