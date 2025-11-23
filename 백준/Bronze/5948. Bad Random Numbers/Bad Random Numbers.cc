#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    bool seen[10000] = { false };
    int count = 0;

    int num = N;

    while (!seen[num]) {
        seen[num] = true;
        count++;

        int middle = (num / 10) % 100;  // 가운데 두 자리
        num = middle * middle;         // 다음 수
    }

    cout << count << endl;
    return 0;
}
