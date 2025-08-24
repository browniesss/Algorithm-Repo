#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long x, y;
        cin >> x >> y;
        long long d = y - x;                

        long long n = (long long)floor(sqrt((long double)d));
        while ((n + 1) * (n + 1) <= d) ++n;
        while (n * n > d) --n;

        long long ans;
        if (d == n * n) {
            ans = 2 * n - 1;
        } else if (d <= n * n + n) {
            ans = 2 * n;
        } else {
            ans = 2 * n + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
