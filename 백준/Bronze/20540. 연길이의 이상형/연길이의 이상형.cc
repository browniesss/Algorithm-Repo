#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; 
    if (!(cin >> s)) return 0;

    auto flip = [](char c) -> char {
        switch (c) {
            case 'E': return 'I';
            case 'I': return 'E';
            case 'S': return 'N';
            case 'N': return 'S';
            case 'T': return 'F';
            case 'F': return 'T';
            case 'J': return 'P';
            case 'P': return 'J';
        }
        return c; // 안전장치(문제 입력은 항상 대문자 4글자)
    };

    for (char &c : s) c = flip(c);
    cout << s << '\n';
    return 0;
}