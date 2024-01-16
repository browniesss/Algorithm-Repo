#include <iostream>
using namespace std;

int T;
int A, B;

int gcd(int a, int b)
{
	while (b!=0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> A >> B;
		cout << lcm(A, B)<<'\n';
	}
}