#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int L;
    cin >> L;
    vector<int> S(L);
    for (int i = 0; i < L; i++) cin >> S[i];
    int n;
    cin >> n;
    
    sort(S.begin(), S.end());

    // n이 S에 있으면 좋은 구간 없음
    if (find(S.begin(), S.end(), n) != S.end()) {
        cout << 0 << "\n";
        return 0;
    }

    int low = 0, high = 1001;
    for (int x : S) {
        if (x < n && x > low) low = x;
        if (x > n && x < high) high = x;
    }

    int A_count = n - (low + 1) + 1;   // A의 가능한 개수
    int B_count = (high - 1) - n + 1; // B의 가능한 개수
    int result = A_count * B_count - 1; // [n,n] 빼기

    cout << result << "\n";
    return 0;
}
