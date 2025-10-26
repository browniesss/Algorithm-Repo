#include <bits/stdc++.h>
using namespace std;

static inline long long cross_ll(long long ax, long long ay, long long bx, long long by) {
    return ax * by - ay * bx;
}

static inline double dist(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long xA, yA, xB, yB, xC, yC;
    if (!(cin >> xA >> yA >> xB >> yB >> xC >> yC)) return 0;

    long long v1x = xB - xA, v1y = yB - yA;
    long long v2x = xC - xA, v2y = yC - yA;
    if (cross_ll(v1x, v1y, v2x, v2y) == 0) {
        cout << -1 << "\n";
        return 0;
    }

    double dAB = dist((double)xA, (double)yA, (double)xB, (double)yB);
    double dAC = dist((double)xA, (double)yA, (double)xC, (double)yC);
    double dBC = dist((double)xB, (double)yB, (double)xC, (double)yC);

    double s1 = dAB + dAC;
    double s2 = dAB + dBC;
    double s3 = dAC + dBC;

    double mn = min(s1, min(s2, s3));
    double mx = max(s1, max(s2, s3));
    double ans = 2.0 * (mx - mn);

    cout.setf(ios::fixed);
    cout << setprecision(10) << ans << "\n";
    return 0;
}
