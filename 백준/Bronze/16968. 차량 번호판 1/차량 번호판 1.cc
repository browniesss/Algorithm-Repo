#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    long long ans = 1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'd') {
            if (i > 0 && s[i-1] == 'd') ans *= 9;   // 직전도 숫자면 같은 숫자 제외
            else                        ans *= 10;  // 아니면 10가지
        } else { // 'c'
            if (i > 0 && s[i-1] == 'c') ans *= 25;  // 직전도 문자면 같은 문자 제외
            else                        ans *= 26;  // 아니면 26가지
        }
    }

    cout << ans << "\n";
    return 0;
}
