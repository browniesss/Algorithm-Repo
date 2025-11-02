#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int e, f, c;
    cin >> e >> f >> c;

    int bottles = e + f;
    int drink = 0;

    while (bottles >= c) {
        int new_drink = bottles / c;
        drink += new_drink;
        bottles = new_drink + (bottles % c);
    }

    cout << drink << "\n";
    return 0;
}
