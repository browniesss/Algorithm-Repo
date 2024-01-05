#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int k, sum = 0;
	stack<int> stk;

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int val;
		cin >> val;

		if (val == 0)
		{
			stk.pop();
			continue;
		}
		stk.push(val);
	}

	while (!stk.empty())
	{
		sum += stk.top();
		stk.pop();
	}

	cout << sum;
}