#include <iostream>
#include <string>

using namespace std;
int main() {
	int n, num = 0;
	char l;

	cin >> n >> l;
	for (int i = 0; i < n; ++i)
    {
		while (to_string(++num).find(l) != string::npos);        
    }

	cout << num << endl;

	return 0;
}