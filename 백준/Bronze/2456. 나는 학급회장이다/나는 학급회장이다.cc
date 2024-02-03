#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n = 0, maxScore = 0, maxIdx = 0, mm;
	int count[3][3] = { 0, };
	int score[3] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		for (int k = 0; k < 3; k++)
		{
			cin >> tmp;

			count[k][tmp - 1]++;
			score[k] += tmp;
		}
	}

	int max = -1;
	for (int i = 0; i < 3; i++)
	{
		int val = score[i];

		if (max < val)
		{
			maxIdx = i;
			maxScore = val;
			max = val;
		}
		else if (max == val)
		{
			int aValue, bValue;
			if (maxIdx == -1)
			{
				aValue = count[mm][2];
			}
			else
			{
				aValue = count[maxIdx][2];
			}
			bValue = count[i][2];

			if (aValue < bValue)
			{
				maxIdx = i;
				maxScore = val;
				max = val;
			}
			else if (aValue == bValue)
			{
				int cValue, dValue;
				if (maxIdx == -1)
				{
					cValue = count[mm][1];
				}
				else
				{
					cValue = count[maxIdx][1];
				}
				dValue = count[i][1];

				if (cValue < dValue)
				{
					maxIdx = i;
					maxScore = val;
					max = val;
				}
				else if (cValue == dValue)
				{
					mm = i;
					maxIdx = -1;
					maxScore = val;
					max = val;
				}
			}
		}
	}

	cout << maxIdx + 1 << " " << maxScore;
}