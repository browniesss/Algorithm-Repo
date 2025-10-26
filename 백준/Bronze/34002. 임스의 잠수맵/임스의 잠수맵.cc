#include <bits/stdc++.h>
using namespace std;

long long ceildiv(long long x, long long y) {
    // y > 0 가정
    return (x + y - 1) / y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    long long S, V;
    long long L;
    if (!(cin >> A >> B >> C)) return 0;
    cin >> S >> V;
    cin >> L;

    long long need = (250 - L) * 100; // 필요한 총 경험치
    long long timeMin = 0;

    // 1) VIP 사우나
    long long vipCapacityMin = V * 30;          // 분
    long long vipTotalGain = C * vipCapacityMin; // 총 경험치
    if (need <= vipTotalGain) {
        timeMin += ceildiv(need, C);
        cout << timeMin << "\n";
        return 0;
    } else {
        need -= vipTotalGain;
        timeMin += vipCapacityMin;
    }

    // 2) 심신 수련관
    long long trainCapacityMin = S * 30;            // 분
    long long trainTotalGain = B * trainCapacityMin; // 총 경험치
    if (need <= trainTotalGain) {
        timeMin += ceildiv(need, B);
        cout << timeMin << "\n";
        return 0;
    } else {
        need -= trainTotalGain;
        timeMin += trainCapacityMin;
    }

    // 3) 이벤트 맵
    timeMin += ceildiv(need, A);

    cout << timeMin << "\n";
    return 0;
}
