#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long mn = (1LL<<62);
    long long mx = -(1LL<<62);

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if (x < mn) mn = x;
        if (x > mx) mx = x;
    }

    cout << 2LL * (mx - mn) << "\n";
    return 0;
}
