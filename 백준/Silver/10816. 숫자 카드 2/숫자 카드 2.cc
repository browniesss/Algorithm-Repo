#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <int, int> map;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int c;
		
		cin >> c;
		map[c]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int c;

		cin >> c;
		cout << map[c] << " ";
	}

	return 0;
}