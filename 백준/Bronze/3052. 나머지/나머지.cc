#include <iostream>
using namespace std;

int main() {
	int num;
	int arr[42] = { 0 };
	int count = 0;

	for (int i = 0; i < 10; i++) {
		cin >> num;
		arr[num % 42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (arr[i] != 0)
			count++;
	}
	cout << count << endl;
}