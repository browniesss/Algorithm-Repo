#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<string> grid(N);
    for (int r = 0; r < N; r++) cin >> grid[r];

    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int,int>> q;

    dist[0][0] = 1; // 시작 칸 포함
    q.push(make_pair(0, 0));

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == N - 1 && c == M - 1) {
            cout << dist[r][c] << '\n';
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (grid[nr][nc] == '0') continue;
            if (dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push(make_pair(nr, nc));
        }
    }

    // 문제에서 항상 도착 가능이라 도달 못하는 경우는 없음.
    return 0;
}
