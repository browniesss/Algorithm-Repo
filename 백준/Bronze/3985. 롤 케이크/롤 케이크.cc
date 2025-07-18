#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int L, N;
    cin >> L >> N;

    vector<int> cake(L + 1, 0); // 1-based 인덱스
    vector<int> cnt(N + 1, 0);  // 각 방청객이 실제로 받은 조각 수

    int expect_max = 0; // 가장 많은 조각을 기대한 양
    int expect_idx = 0; // 가장 많은 조각을 기대한 방청객 번호

    for (int i = 1; i <= N; i++) {
        int P, K;
        cin >> P >> K;
        int expected = K - P + 1;
        if (expected > expect_max) {
            expect_max = expected;
            expect_idx = i;
        }

        // 실제 조각 할당
        for (int j = P; j <= K; j++) {
            if (cake[j] == 0) {
                cake[j] = i;
                cnt[i]++;
            }
        }
    }

    // 실제로 가장 많이 받은 사람 찾기
    int real_max = 0;
    int real_idx = 0;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] > real_max) {
            real_max = cnt[i];
            real_idx = i;
        }
    }

    cout << expect_idx << '\n' << real_idx << '\n';

    return 0;
}
