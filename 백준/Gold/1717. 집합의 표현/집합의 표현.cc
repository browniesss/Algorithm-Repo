#include <bits/stdc++.h>
using namespace std;

static vector<int> parent;
static vector<int> sz;

int find_set(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

bool union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 0; i <= n; ++i) parent[i] = i;

    ostringstream out;
    for (int i = 0; i < m; ++i) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            union_set(a, b);
        } else if (op == 1) {
            if (find_set(a) == find_set(b)) out << "YES\n";
            else out << "NO\n";
        }
    }

    cout << out.str();
    return 0;
}
