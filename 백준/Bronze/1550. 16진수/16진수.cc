#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	char c[16];
	int i;

	cin >> c;
	
	i = (int)strtol(c, NULL, 16);

	printf("%d", i);
}