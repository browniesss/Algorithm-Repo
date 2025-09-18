#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> up(n), down(n);
        for (int i = 0; i < n; ++i) cin >> up[i];
        for (int i = 0; i < n; ++i) cin >> down[i];

        if (n == 1) {
            cout << max(up[0], down[0]) << '\n';
            continue;
        }

        // DP 배열
        vector<int> top(n, 0), bottom(n, 0);

        // 초기값
        top[0] = up[0];
        bottom[0] = down[0];

        top[1] = bottom[0] + up[1];
        bottom[1] = top[0] + down[1];

        // 점화식
        for (int i = 2; i < n; ++i) {
            // i에서 위를 선택: (i-1의 아래) 또는 (i-2의 아래)에서만 이어붙일 수 있음
            int cand1 = bottom[i - 1];
            int cand2 = bottom[i - 2];
            top[i] = max(cand1, cand2) + up[i];

            // i에서 아래를 선택: (i-1의 위) 또는 (i-2의 위)
            int cand3 = top[i - 1];
            int cand4 = top[i - 2];
            bottom[i] = max(cand3, cand4) + down[i];
        }

        cout << max(top[n - 1], bottom[n - 1]) << '\n';
    }
    return 0;
}
