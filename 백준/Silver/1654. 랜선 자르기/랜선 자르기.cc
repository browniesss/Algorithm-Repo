#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int main()
{
	int k, n, answer = 0;
	cin >> k >> n;

	long long start = 1;
	long long mid = 0;
	long long end;

	vector<int> lines(k);

	for (int i = 0; i < k; i++)
	{
		cin >> lines[i];
	}
	sort(lines.begin(), lines.end());
	end = lines.back();

	while (start <= end)
	{
		int temp = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < k; i++)
		{
			temp += lines[i] / mid;
		}

		if (temp < n)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;

			if (mid <= end)
				answer = mid;
		}
	}

	cout << answer;
}