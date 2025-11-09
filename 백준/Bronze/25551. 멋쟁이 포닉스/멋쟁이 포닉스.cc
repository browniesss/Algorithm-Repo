#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long MW, MB, TW, TB, PW, PB;
    if (!(cin >> MW >> MB)) return 0;
    cin >> TW >> TB;
    cin >> PW >> PB;

    long long x = min(TW, min(MB, PB));
    long long y = min(TB, min(MW, PW));

    long long ans = min(x + y, 2 * min(x, y) + 1);
    cout << ans << "\n";
    return 0;
}
