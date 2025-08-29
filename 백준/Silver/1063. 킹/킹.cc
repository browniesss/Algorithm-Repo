#include <bits/stdc++.h>
using namespace std;

bool inBoard(int r, int c) { return 0 <= r && r < 8 && 0 <= c && c < 8; }

void moveDelta(const string& cmd, int &dr, int &dc) {
    dr = 0; dc = 0;
    if (cmd == "R")  { dc = 1; }
    else if (cmd == "L") { dc = -1; }
    else if (cmd == "B") { dr = -1; }
    else if (cmd == "T") { dr = 1; }
    else if (cmd == "RT"){ dr = 1; dc = 1; }
    else if (cmd == "LT"){ dr = 1; dc = -1; }
    else if (cmd == "RB"){ dr = -1; dc = 1; }
    else if (cmd == "LB"){ dr = -1; dc = -1; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string king, stone;
    int N;
    if (!(cin >> king >> stone >> N)) return 0;

    // to r,c (0-based, bottom row=0)
    int kr = king[1] - '1';
    int kc = king[0] - 'A';
    int sr = stone[1] - '1';
    int sc = stone[0] - 'A';

    for (int i = 0; i < N; ++i) {
        string cmd; cin >> cmd;
        int dr, dc; moveDelta(cmd, dr, dc);

        int nkr = kr + dr, nkc = kc + dc;
        if (!inBoard(nkr, nkc)) continue; // king out -> skip

        if (nkr == sr && nkc == sc) {
            int nsr = sr + dr, nsc = sc + dc;
            if (!inBoard(nsr, nsc)) continue; // stone out -> skip whole move
            // move both
            sr = nsr; sc = nsc;
            kr = nkr; kc = nkc;
        } else {
            // move king only
            kr = nkr; kc = nkc;
        }
    }

    // back to chess notation
    cout << char('A' + kc) << char('1' + kr) << "\n";
    cout << char('A' + sc) << char('1' + sr) << "\n";
    return 0;
}
