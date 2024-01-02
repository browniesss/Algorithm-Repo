#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int c[50];
int d[50];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	stack<char> stk;
	queue<char> que;
	int check = 0;

	cin >> s;
	if (s.length() == 1) {
		cout << s;
		return 0;
	}

	for (int i = 0; i < s.length(); i++)
	{
		c[s[i] - 'A']++;
	}

	for (int i = 0; i < 50; i++)
	{
		if (c[i] == 0)
			continue;

		for (int k = 0; k < (c[i] / 2); k++)
		{
			que.push((char)(i + 'A'));
			stk.push((char)(i + 'A'));
		}

		if (c[i] % 2 == 1)
		{
			d[i]++;
			check++;
		}
	}

	if (stk.empty() || check >= 2)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	while (!que.empty())
	{
		cout << que.front();
		que.pop();
	}

	for (int i = 0; i < 50; i++)
	{
		if (d[i] == 0)
			continue;

		cout << (char)(i + 'A');
	}

	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}