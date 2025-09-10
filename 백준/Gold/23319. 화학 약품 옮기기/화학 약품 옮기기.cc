#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 정점 인덱스: A: 0..n-1, B: n..2n-1
    int N = 2 * n;
    vector<vector<int>> adj(N);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;              // 0-index
        int u = a;             // A-side
        int v = n + b;         // B-side
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 연결요소별 (a_cnt, b_cnt) 수집
    vector<int> compA, compB;
    vector<int> vis(N, 0);
    for (int s = 0; s < N; ++s) if (!vis[s]) {
        queue<int> q;
        vis[s] = 1; q.push(s);
        int a_cnt = 0, b_cnt = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u < n) ++a_cnt; else ++b_cnt;
            for (int w : adj[u]) if (!vis[w]) {
                vis[w] = 1; q.push(w);
            }
        }
        compA.push_back(a_cnt);
        compB.push_back(b_cnt);
    }

    // DP: reachable[delta][s]
    // delta in [-n..n] -> index = delta + offset, offset = n
    const int OFF = n;
    vector<vector<char>> dp(2*n + 1, vector<char>(n + 1, 0));
    dp[OFF][0] = 1;

    for (size_t i = 0; i < compA.size(); ++i) {
        int a = compA[i], b = compB[i];
        int w = a - b;
        vector<vector<char>> ndp = dp; // 선택 안 함

        for (int d = -n; d <= n; ++d) {
            for (int sA = 0; sA <= n; ++sA) {
                if (!dp[d + OFF][sA]) continue;
                int nd = d + w;
                int ns = sA + a;
                if (nd < -n || nd > n) continue;
                if (ns > n) continue;
                ndp[nd + OFF][ns] = 1; // 선택 함
            }
        }
        dp.swap(ndp);
    }

    int ans = 0;
    for (int sA = 0; sA <= n/2; ++sA) {
        if (dp[OFF][sA]) ans = sA;
    }
    cout << ans << "\n";
    return 0;
}
