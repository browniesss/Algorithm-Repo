#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; 
    if (!(cin >> s)) return 0;
    sort(s.rbegin(), s.rend());      // 내림차순 정렬
    cout << s << '\n';
    return 0;
}
