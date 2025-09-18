#include <bits/stdc++.h>
using namespace std;

int idx(char c) {
    // A->0, C->1, G->2, T->3
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    return 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Slen, P;
    if (!(cin >> Slen >> P)) return 0;
    string S;
    cin >> S;

    int need[4];
    for (int i = 0; i < 4; ++i) cin >> need[i];

    int have[4] = {0,0,0,0};
    int satisfied = 0;

    // 처음에 need[i] == 0이면 이미 만족된 것으로 처리
    for (int i = 0; i < 4; ++i) {
        if (need[i] == 0) satisfied++;
    }

    // 초기 윈도우(처음 P 문자)를 채우면서 satisfied 업데이트
    for (int i = 0; i < P; ++i) {
        int k = idx(S[i]);
        // 증가 전 상태가 요구를 만족하지 못했는지 확인
        if (have[k] < need[k] && have[k] + 1 >= need[k]) {
            satisfied++;
        }
        have[k]++;
    }

    int result = 0;
    if (satisfied == 4) result++;

    // 슬라이딩: 윈도우 시작을 1부터 Slen-P 까지 이동
    for (int start = 1; start <= Slen - P; ++start) {
        // 나가는 문자: S[start-1]
        int outC = idx(S[start - 1]);
        // 감소하기 전 상태가 요구를 만족했는데, 감소 후 만족하지 않게 되면 satisfied--
        if (have[outC] >= need[outC] && have[outC] - 1 < need[outC]) {
            satisfied--;
        }
        have[outC]--;

        // 들어오는 문자: S[start + P - 1]
        int inC = idx(S[start + P - 1]);
        if (have[inC] < need[inC] && have[inC] + 1 >= need[inC]) {
            satisfied++;
        }
        have[inC]++;

        if (satisfied == 4) result++;
    }

    cout << result << '\n';
    return 0;
}
