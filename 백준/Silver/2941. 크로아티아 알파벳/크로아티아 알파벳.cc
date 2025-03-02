#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int cnt = 0;
	vector<string> lists = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string st;

	cin >> st;

	for (int i = 0; i < lists.size(); i++)
	{
		while (true)
		{
			int val = st.find(lists[i]);

			if (val == -1)
				break;

			st.replace(val, lists[i].length(), "#");
			cnt++;

		}
	}

	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] != '#')
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}