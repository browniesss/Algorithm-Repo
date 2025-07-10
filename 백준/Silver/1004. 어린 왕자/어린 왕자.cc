#include <iostream>
#include <cmath>
using namespace std;

bool isInside(int x, int y, int cx, int cy, int r) {
    int dx = x - cx;
    int dy = y - cy;
    return dx * dx + dy * dy < r * r;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;

        int count = 0;
        for (int i = 0; i < n; ++i) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool startInside = isInside(x1, y1, cx, cy, r);
            bool endInside = isInside(x2, y2, cx, cy, r);

            // 한 점만 내부에 있을 때만 +1
            if (startInside != endInside)
                count++;
        }

        cout << count << '\n';
    }

    return 0;
}
