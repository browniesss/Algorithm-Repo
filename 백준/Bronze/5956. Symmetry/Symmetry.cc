#include <iostream>

using namespace std;

using ll = long long;

ll countCows(ll n, ll m) {
    // 종료 조건: 가운데가 없으면 소를 놓지 않음
    if (n % 2 == 0 || m % 2 == 0) return 0;

    // 중앙에 1마리 + 4개 구역에 대해 재귀
    return 1 + 4 * countCows(n / 2, m / 2);
}

int main() {
    ll N, M;
    cin >> N >> M;

    cout << countCows(N, M) << endl;
    return 0;
}