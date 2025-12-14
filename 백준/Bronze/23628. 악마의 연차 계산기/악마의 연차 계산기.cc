#include <bits/stdc++.h>
using namespace std;

static long long toSerial(long long y, long long m, long long d) {
    return (y - 1) * 360LL + (m - 1) * 30LL + (d - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sy, sm, sd;
    long long ey, em, ed;
    cin >> sy >> sm >> sd;
    cin >> ey >> em >> ed;

    long long S = toSerial(sy, sm, sd);
    long long E = toSerial(ey, em, ed);
    long long diff = E - S;

    long long monthLeave = min(36LL, diff / 30LL);

    long long Y = diff / 360LL;
    long long m = Y / 2LL;

    long long sumA;
    if (Y % 2LL == 0) sumA = m * (m - 1); // Y = 2m
    else             sumA = m * m;       // Y = 2m+1

    long long yearLeave = 15LL * Y + sumA;

    cout << yearLeave << " " << monthLeave << "\n";
    cout << diff << "days\n"; // 
    return 0;
}
