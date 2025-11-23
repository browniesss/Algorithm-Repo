#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int n;
int dp[201]; // -1: 아직 모름, 0: 불가능, 1: 가능

int solve(int pos) {
    // pos부터 끝까지가 (100+1+ | 01)+ 인지 확인
    if (pos == n) {
        // 최소 한 블록은 있어야 하므로 여기서 true가 아님
        return 0;
    }

    int &ret = dp[pos];
    if (ret != -1) return ret;
    ret = 0;

    // 1) "01" 패턴 시도
    if (pos + 1 < n && s[pos] == '0' && s[pos + 1] == '1') {
        int nextPos = pos + 2;
        if (nextPos == n || solve(nextPos)) {
            ret = 1;
            return ret;
        }
    }

    // 2) "100+1+" 패턴 시도
    if (pos + 2 < n && s[pos] == '1' && s[pos + 1] == '0' && s[pos + 2] == '0') {
        int k = pos + 3; // "100" 뒤에서 시작

        // 0들을 가능한 만큼 먹는다 (100+ 부분)
        while (k < n && s[k] == '0') {
            k++;
        }

        // 최소 한 개의 1이 있어야 함 (100+1+)
        if (k < n && s[k] == '1') {
            int t = k;
            // 연속된 1들을 하나씩 늘려가며, 어디까지를 이 블록으로 볼지 모두 시도
            while (t < n && s[t] == '1') {
                int nextPos = t + 1; // 이 1까지를 포함한 블록 뒤 위치

                if (nextPos == n || solve(nextPos)) {
                    ret = 1;
                    return ret;
                }
                t++;
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        n = (int)s.size();

        for (int i = 0; i <= n; i++) {
            dp[i] = -1;
        }

        if (solve(0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
