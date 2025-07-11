#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count0 = 0;
    int count1 = 0;

    // 첫 문자 기준으로 그룹 카운트 초기화
    if (s[0] == '0') count0++;
    else count1++;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '0') count0++;
            else count1++;
        }
    }

    cout << min(count0, count1) << '\n';
    return 0;
}