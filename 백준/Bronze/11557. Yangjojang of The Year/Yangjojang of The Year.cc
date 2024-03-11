#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		int max = -1;
		string maxstring = "";

		cin >> n;
		for (int k = 0; k < n; k++)
		{
			int num;
			string s;

			cin >> s >> num;

			if (num >= max)
			{
				max = num;
				maxstring = s;
			}
		}

		cout << maxstring << endl;
	}

	return 0;
}