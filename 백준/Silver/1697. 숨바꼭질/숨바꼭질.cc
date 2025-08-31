#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    if (!(cin >> N >> K)) return 0;

    if (N >= K) {                 // 뒤로 걷기만 하면 됨
        cout << (N - K) << '\n';
        return 0;
    }

    const int MAX = 100000;
    vector<int> dist(MAX + 1, -1);
    queue<int> q;
    dist[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == K) {             // 목표 도달
            cout << dist[x] << '\n';
            return 0;
        }
        // 다음 후보들
        int nexts[3] = { x - 1, x + 1, x * 2 };
        for (int nx : nexts) {
            if (0 <= nx && nx <= MAX && dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }
    return 0;
}
