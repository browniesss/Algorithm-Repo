#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int n, k;
unordered_set<string> s;
bool visited[11];
vector<string> vec;


void DFS(int depth, string cur)
{
	if (depth == k)
	{
		s.insert(cur);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i])
			continue;

		visited[i] = true;
		DFS(depth + 1, cur + vec[i]);
		visited[i] = false;
	}
}

int main()
{
	cin >> n >> k;
	vec.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	DFS(0, "");

	cout << s.size() << '\n';

	return 0;
}