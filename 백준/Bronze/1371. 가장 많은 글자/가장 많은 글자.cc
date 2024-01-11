#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int arr[45] = { 0, };
	char s;

	while(cin >> s)
	{
		arr[(s - 'a')]++;
	}

	int max = 0;
	for (int i = 0; i < 45; i++)
	{
		if (max <= arr[i])
		{
			max = arr[i];
		}
	}

	for (int i = 0; i < 45; i++)
	{
		if (max == arr[i])
			cout << (char)(i + 97);
	}
}