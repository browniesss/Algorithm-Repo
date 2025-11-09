#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<long long> S(n + 1, 0), A(n + 1, 0);

        for (int i = 0; i < m; ++i) {
            int a, b, p, q;
            cin >> a >> b >> p >> q;
            S[a] += p;
            A[a] += q;
            S[b] += q;
            A[b] += p;
        }

        long double maxW = -1.0L;
        long double minW = 2.0L;

        for (int i = 1; i <= n; ++i) {
            long double s = static_cast<long double>(S[i]);
            long double a = static_cast<long double>(A[i]);
            long double W;
            if (S[i] == 0 && A[i] == 0) {
                W = 0.0L;
            } else {
                long double s2 = s * s;
                long double a2 = a * a;
                W = s2 / (s2 + a2);
            }
            if (W > maxW) maxW = W;
            if (W < minW) minW = W;
        }

        long long ansMax = static_cast<long long>(floor(maxW * 1000.0L + 1e-12L));
        long long ansMin = static_cast<long long>(floor(minW * 1000.0L + 1e-12L));

        cout << ansMax << "\n" << ansMin << "\n";
    }
    return 0;
}
