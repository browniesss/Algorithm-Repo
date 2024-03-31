#include <iostream>
using namespace std;

int main() {

	int n, c;
	cin >> n >> c;

	int *tmp = new int[n];

	for (int i = 0; i < n; i++) 
		cin >> tmp[i];
	
	int flag = 0,cnt = 0;
	for (int i = 1; i <= c; i++) {
		for (int j = 0; j < n; j++)
		{
			if (i%tmp[j] == 0)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 1)
		{
			cnt++;
			flag = 0;
		}
	}
	cout << cnt;
}