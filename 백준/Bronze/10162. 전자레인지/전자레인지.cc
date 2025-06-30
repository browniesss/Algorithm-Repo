#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    if (T % 10 != 0) {
        cout << -1 << endl;
        return 0;
    }

    int A = 300, B = 60, C = 10;
    int a = T / A;
    T %= A;

    int b = T / B;
    T %= B;

    int c = T / C;
    T %= C;

    cout << a << " " << b << " " << c << endl;
    return 0;
}