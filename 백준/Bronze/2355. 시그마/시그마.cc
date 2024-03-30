#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);
    long long a, b;
    cin >> a >> b;
    cout << (((a + b) * (abs(b - a) + 1)) >> 1);
	return 0;
}