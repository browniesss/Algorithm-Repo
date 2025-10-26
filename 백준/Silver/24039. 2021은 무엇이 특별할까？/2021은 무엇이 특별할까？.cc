#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (int d = 3; 1LL * d * d <= x; d += 2) {
        if (x % d == 0) return false;
    }
    return true;
}

int nextPrime(int x) {
    if (x <= 2) return 2;
    if (x % 2 == 0) ++x;
    while (!isPrime(x)) x += 2;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    int p = 2;
    int q = 3;

    while (1LL * p * q <= N) {
        p = q;
        q = nextPrime(q + 1);
    }

    cout << 1LL * p * q << "\n";
    return 0;
}
