#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    for (int A = 1; A <= 999; ++A) {
        string current;
        for (int B = A; B <= 999; ++B) {
            current += to_string(B);
            if (current.length() > S.length()) break;
            if (current == S) {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }

    return 0;
}
