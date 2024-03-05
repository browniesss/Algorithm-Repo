#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int number = 0;
	while (true)
	{
		int sum = 0;
		vector<int> vec;
		cin >> number;

		if (number == -1)
			break;

		for (int i = number - 1; i > 0; i--)
		{
			if (number % i == 0)
			{
				sum += i;
				vec.push_back(i);
			}
		}

		if (number != sum)
		{
			cout << number << " is NOT perfect." << "\n";
		}
		else
		{
			cout << number << " = ";
			int size = vec.size() - 1;
			for (int i = 0; i < size; i++)
			{
				int val = vec.back();
				vec.pop_back();
				cout << val << " + ";
			}
			cout << vec.back() << "\n";
		}
	}

	return 0;
}