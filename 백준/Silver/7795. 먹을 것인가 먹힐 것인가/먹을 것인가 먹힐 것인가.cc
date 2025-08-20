#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(M);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < M; ++i) cin >> B[i];

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        long long ans = 0;
        int j = 0; // B에서 a보다 작은 원소 개수를 가리키는 포인터
        for (int a : A) {
            while (j < M && B[j] < a) ++j;
            ans += j; // B[0..j-1]는 모두 a보다 작다
        }
        cout << ans << '\n';
    }
    return 0;
}
