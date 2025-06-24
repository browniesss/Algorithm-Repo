#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // (값, 인덱스) 쌍을 저장
    vector<pair<int, int>> paired;
    for (int i = 0; i < N; ++i)
        paired.push_back({A[i], i});

    // 값 기준으로 정렬 (값이 같으면 인덱스 작은 순으로)
    sort(paired.begin(), paired.end());

    // P[i] = B에서 A[i]가 들어갈 위치
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        int a_index = paired[i].second;
        P[a_index] = i;
    }

    for (int i = 0; i < N; ++i)
        cout << P[i] << " ";
    cout << "\n";

    return 0;
}
