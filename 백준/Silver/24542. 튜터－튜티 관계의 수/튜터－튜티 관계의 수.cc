#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent;
    vector<int> sz;

    DSU(int n_) : n(n_), parent(n_ + 1), sz(n_ + 1, 1) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find_set(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }

    void unite(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return;
        // union by size
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int size_of(int x) {
        return sz[find_set(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long MOD = 1000000007LL;

    int N, M;
    if (!(cin >> N >> M)) return 0;

    DSU dsu(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    // 연결 요소별 크기들의 곱
    long long ans = 1;
    vector<bool> counted(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        int r = dsu.find_set(i);
        if (!counted[r]) {
            counted[r] = true;
            ans = (ans * dsu.sz[r]) % MOD;
        }
    }

    cout << ans % MOD << "\n";
    return 0;
}
