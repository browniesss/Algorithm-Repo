#include <bits/stdc++.h>
using namespace std;

int lower_bound_idx(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size();        // [l, r)
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] < x) l = m + 1;
        else          r = m;
    }
    return l; // 처음으로 a[i] >= x 인 i (없으면 n)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; ++i) cin >> cards[i];
    sort(cards.begin(), cards.end());

    cin >> M;
    string out;
    out.reserve(M * 2); // 대략 "0 " or "1 " * M

    for (int i = 0; i < M; ++i) {
        int x; cin >> x;
        int idx = lower_bound_idx(cards, x);
        out += (idx < (int)cards.size() && cards[idx] == x) ? '1' : '0';
        out += (i + 1 == M) ? '\n' : ' ';
    }
    cout << out;
    return 0;
}