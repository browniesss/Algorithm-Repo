#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == 1) c1++;
        else if (A[i] == 2) c2++;
        else if (A[i] == 3) c3++;
    }

    int U, D;
    cin >> U >> D;

    // 불가능한 경우: 전용 옷걸이에 걸 옷이 부족
    if (U < c1 || D < c2) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    int remU = U;
    int remD = D;
    string ans(N, 'U'); // 일단 기본값은 U로 채워 두자

    for (int i = 0; i < N; i++) {
        if (A[i] == 1) {
            // 상의 전용
            ans[i] = 'U';
            remU--;
        } else if (A[i] == 2) {
            // 하의 전용
            ans[i] = 'D';
            remD--;
        } 
        // 타입 3은 나중에 처리 (지금은 일단 넘어감)
    }

    // 타입 3(공용) 옷걸이 처리: 남은 상의 먼저, 그 다음 남은 하의
    for (int i = 0; i < N; i++) {
        if (A[i] == 3) {
            if (remU > 0) {
                ans[i] = 'U';
                remU--;
            } else {
                ans[i] = 'D';
                remD--;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
