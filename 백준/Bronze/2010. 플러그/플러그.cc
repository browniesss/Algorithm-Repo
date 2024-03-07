#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	int num;
	int sum = 0;

	cin >> n;

	while (n--) 
    {
		cin >> num;
		sum += num - 1;
	}

	cout << sum + 1 << endl;

	return 0;
}