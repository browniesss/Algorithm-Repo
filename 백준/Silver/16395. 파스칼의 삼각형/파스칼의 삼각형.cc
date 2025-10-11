#include <bits/stdc++.h>
using namespace std;

long long comb(int n, int r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    long long num = 1, den = 1;
    for (int i = 1; i <= r; ++i) {
        num *= (n - r + i);   
        den *= i;             
        long long g = std::gcd(num, den);
        num /= g; den /= g;   
    }
    return num;              
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    cout << comb(n - 1, k - 1) << '\n';
    return 0;
}
