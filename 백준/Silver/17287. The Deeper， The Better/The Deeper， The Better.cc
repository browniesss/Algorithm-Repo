#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int max = 0;
	int sum = 0;
	stack<char> st;
	string str;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];

		if (c == '(')
		{
			sum += 1;
			st.push(c);
		}
		else if (c == '{')
		{
			sum += 2;
			st.push(c);
		}
		else if (c == '[')
		{
			sum += 3;
			st.push(c);
		}
		else if (c == ')')
		{
			sum -= 1;
			st.pop();
		}
		else if (c == '}')
		{
			sum -= 2;
			st.pop();
		}
		else if (c == ']')
		{
			sum -= 3;
			st.pop();
		}

		if (c >= '0' && c <= '9' && sum >= max)
		{
			max = sum;
		}
	}

	cout << max << '\n';

	return 0;
}