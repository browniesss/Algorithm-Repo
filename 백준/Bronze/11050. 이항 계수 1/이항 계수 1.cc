#include <iostream>

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;

	return factorial(n - 1) * n;
}

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;

	cin >> n >> k;

	cout << factorial(n) / (factorial(k) * factorial(n - k)) << endl;
	
	return 0;
}