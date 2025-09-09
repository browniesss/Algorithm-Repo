
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<pair<int,int>> chap(M);
    for (int i = 0; i < M; ++i) {
        int days, pages;
        cin >> days >> pages;
        chap[i] = {days, pages};
    }

    vector<int> dp(N + 1, 0); // dp[d]: d일 이내 최대 페이지
    for (auto [t, p] : chap) {
        for (int d = N; d >= t; --d) {
            dp[d] = max(dp[d], dp[d - t] + p);
        }
    }

    cout << dp[N] << "\n";
    return 0;
}
