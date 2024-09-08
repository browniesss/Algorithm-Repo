#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int main()
{
	int n, m, answer = 0;
	cin >> n;

	vector<int> lists(n);
	for (int i = 0; i < n; i++)
	{
		cin >> lists[i];
	}
	cin >> m;

	sort(lists.begin(), lists.end());

	int start = 1;
	int end = lists.back();
	int mid = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;

		int temp = m;

		for (int i = 0; i < n; i++)
		{
			temp -= mid < lists[i] ? mid : lists[i];
		}

		if (temp > 0)
		{
			start = mid + 1;
			answer = mid;
		}
		else if (temp == 0)
		{
			answer = mid;
			break;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << answer;
}