#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	string a, b;
	int r, c;
	bool flag = false;
	cin >> a >> b;

	/*
	A = "ABBA"이고, B = "CCBB"

	.C..
	.C..
	ABBA
	.B..
	*/

	for (int i = 0; i < a.length(); i++)
	{
		for (int k = 0; k < b.length(); k++)
		{
			if (a[i] == b[k])
			{
				r = i;
				c = k;
				flag = true;
				break;
			}

			if (flag)
				break;
		}

		if (flag)
			break;
	}

	for (int i = 0; i < b.length(); i++)
	{
		for (int k = 0; k < a.length(); k++)
		{
			if (k == r && i != c)
			{
				cout << b[i];
			}
			else if(k != r && i != c)
			{
				cout << ".";
			}
			else if (i == c)
			{
				cout << a[k];
			}
		}
		cout << "\n";
	}

	return 0;
}