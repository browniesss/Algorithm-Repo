#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        double num;
        cin >> num;

        string op;
        while (cin.peek() == ' ') cin.get(); // 공백 처리
        while (cin.peek() != '\n' && cin >> op) {
            if (op == "@") num *= 3;
            else if (op == "%") num += 5;
            else if (op == "#") num -= 7;
        }

        cout << fixed << setprecision(2) << num << '\n';
    }
    return 0;
}
