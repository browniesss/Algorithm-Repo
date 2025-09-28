#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string layout = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    // 오른쪽 키 -> 왼쪽 키 매핑
    unordered_map<char,char> L;
    for (size_t i = 1; i < layout.size(); ++i) L[layout[i]] = layout[i-1];
    L[' '] = ' ';

    string line;
    while (getline(cin, line)) {
        for (char &c : line) {
            if (L.count(c)) cout << L[c];
            else cout << c; // (문제 조건상 안 나오지만 방어)
        }
        cout << '\n';
    }
    return 0;
}
