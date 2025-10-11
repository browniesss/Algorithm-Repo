#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<char> infected(N + 1, 0);
    int healthy_cnt = N;

    while (Q--) {
        int op; 
        cin >> op;
        if (op == 1) {
            int x; cin >> x;
            if (!infected[x]) {
                infected[x] = 1;
                --healthy_cnt;
            }
        } else if (op == 2) {
            int x; cin >> x;
            if (infected[x]) {
                infected[x] = 0;
                ++healthy_cnt;
            }
        } else if (op == 3) {
            cout << healthy_cnt << '\n';
        }
    }
    return 0;
}
