#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (line == "#") break;

        string a, b, c;
        {
            stringstream ss(line);
            ss >> a >> b >> c;
        }

        string d = c;
        for (size_t i = 0; i < a.size(); ++i) {
            int shift = ( (b[i] - 'a') - (a[i] - 'a') + 26 ) % 26;        
            d[i] = char('a' + ((c[i] - 'a' + shift) % 26));               
        }

        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
    return 0;
}
