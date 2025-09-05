#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N, M;
        if (!(cin >> N >> M)) return 0;
        if (N == 0 && M == 0) break;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        long long ans = 0;
        int i = 0; // pointer on A

        for (int j = 0; j < M; ++j) {
            int b; cin >> b;

            while (i < N && A[i] < b) ++i; // A를 b까지 끌어올림
            if (i < N && A[i] == b) {     // 공통 발견
                ++ans;
                ++i;                       // A는 중복이 없으므로 한 칸 전진
            }
            // A[i] > b면 다음 b로 넘어감
        }

        cout << ans << '\n';
    }
    return 0;
}
