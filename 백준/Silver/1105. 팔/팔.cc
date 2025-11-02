#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string L, R;
    if (!(cin >> L >> R)) return 0;

    if (L.size() != R.size()) {
        cout << 0 << "\n";
        return 0;
    }

    int cnt = 0;
    for (size_t i = 0; i < L.size(); i++) {
        if (L[i] != R[i]) break;           
        if (L[i] == '8') cnt++;            
    }

    cout << cnt << "\n";
    return 0;
}
