#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> D(N + 1, 0);
        for (int i = 1; i <= N; i++) cin >> D[i];

        vector<vector<int> > adj(N + 1);
        vector<int> indeg(N + 1, 0);

        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            adj[X].push_back(Y);
            indeg[Y]++;
        }

        int W;
        cin >> W;

        vector<long long> dp(N + 1, 0);
        queue<int> q;

        for (int i = 1; i <= N; i++) {
            if (indeg[i] == 0) {
                dp[i] = D[i];
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (size_t i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (dp[v] < dp[u] + D[v]) dp[v] = dp[u] + D[v];
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }

        cout << dp[W] << "\n";
    }
    return 0;
}
