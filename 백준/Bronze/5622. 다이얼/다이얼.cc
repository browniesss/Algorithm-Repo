#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int getTime(char ch) {
	if (ch >= 'A' && ch <= 'C') return 3;
	if (ch >= 'D' && ch <= 'F') return 4;
	if (ch >= 'G' && ch <= 'I') return 5;
	if (ch >= 'J' && ch <= 'L') return 6;
	if (ch >= 'M' && ch <= 'O') return 7;
	if (ch >= 'P' && ch <= 'S') return 8;
	if (ch >= 'T' && ch <= 'V') return 9;
	if (ch >= 'W' && ch <= 'Z') return 10;
	return 0;
}

int main()
{
	int sum = 0;
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		sum += getTime(s[i]);
	}

	cout << sum << '\n';

	return 0;
}