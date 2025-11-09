#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    vector<long long> decs;
    decs.reserve(1023);

    for (int mask = 1; mask < (1 << 10); ++mask) {
        long long x = 0;
        for (int d = 9; d >= 0; --d) {
            if (mask & (1 << d)) {
                x = x * 10 + d;
            }
        }
        decs.push_back(x);
    }

    sort(decs.begin(), decs.end());

    if (N >= (long long)decs.size()) {
        cout << -1 << "\n";
    } else {
        cout << decs[(size_t)N] << "\n";
    }
    return 0;
}
