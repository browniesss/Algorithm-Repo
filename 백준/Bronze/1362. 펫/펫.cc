#include<iostream>

using namespace std;

int main()
{
    int o, w;
    int scenario = 1;

    while (cin >> o >> w) {
        if (o == 0 && w == 0) break;

        char c;
        int n;
        bool isDead = false;

        while (cin >> c >> n) {
            if (c == '#' && n == 0) break;

            if (isDead) continue;

            if (c == 'E') {
                w -= n;
                if (w <= 0) isDead = true;
            }
            else if (c == 'F') {
                w += n;
            }
        }

        cout << scenario++ << " ";
        if (isDead || w <= 0) {
            cout << "RIP\n";
        }
        else if (w > o / 2 && w < o * 2) {
            cout << ":-)\n";
        }
        else {
            cout << ":-(" << '\n';
        }
    }


    return 0;
}