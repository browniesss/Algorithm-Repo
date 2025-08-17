#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) cin >> A[i];

    int s;
    cin >> s;

    vector<char> visited(n + 1, 0);
    queue<int> q;

    visited[s] = 1;
    q.push(s);
    int cnt = 0;

    while (!q.empty()) {
        int i = q.front(); q.pop();
        cnt++;

        int left = i - A[i];
        if (left >= 1 && !visited[left]) {
            visited[left] = 1;
            q.push(left);
        }

        int right = i + A[i];
        if (right <= n && !visited[right]) {
            visited[right] = 1;
            q.push(right);
        }
    }

    cout << cnt << "\n";
    return 0;
}
