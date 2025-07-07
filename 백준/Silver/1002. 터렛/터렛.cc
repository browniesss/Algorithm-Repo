#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = hypot(x2 - x1, y2 - y1);

        if (d == 0 && r1 == r2) {
            cout << -1 << '\n';  // 겹침
        } else if (d == 0 || d > r1 + r2 || d < abs(r1 - r2)) {
            cout << 0 << '\n';  // 만나는 점 없음
        } else if (d == r1 + r2 || d == abs(r1 - r2)) {
            cout << 1 << '\n';  // 외접 또는 내접
        } else {
            cout << 2 << '\n';  // 두 점에서 만남
        }
    }

    return 0;
}
