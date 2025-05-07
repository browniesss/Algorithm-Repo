#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
	int n;
	vector<long long> vec;
	cin >> n;

	vec.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(), greater<long long>());

	long long answer = 0;

	for (int i = 0; i < n; i++)
	{
		answer = max(answer, vec[i] * (i + 1LL));
	}

	cout << answer << '\n';

	return 0;
}