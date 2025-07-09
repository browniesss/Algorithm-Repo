#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int minPackage = 1000;
    int minSingle = 1000;

    for (int i = 0; i < M; ++i) {
        int pack, single;
        cin >> pack >> single;
        minPackage = min(minPackage, pack);
        minSingle = min(minSingle, single);
    }

    int cost1 = N * minSingle;

    int cost2 = ((N + 5) / 6) * minPackage;

    int cost3 = (N / 6) * minPackage + (N % 6) * minSingle;

    int answer = min({cost1, cost2, cost3});
    cout << answer << endl;

    return 0;
}
