#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, double> score = {
        {"A+", 4.5}, {"A0", 4.0},
        {"B+", 3.5}, {"B0", 3.0},
        {"C+", 2.5}, {"C0", 2.0},
        {"D+", 1.5}, {"D0", 1.0},
        {"F",  0.0}
    };

    string name, grade;
    double credit;
    double sum_w = 0.0;
    double sum_c = 0.0;

    for (int i = 0; i < 20; ++i) {
        if (!(cin >> name >> credit >> grade)) return 0;
        if (grade == "P") continue;
        sum_w += credit * score[grade];
        sum_c += credit;
    }

    cout << fixed << setprecision(6) << (sum_w / sum_c) << '\n';
    return 0;
}
