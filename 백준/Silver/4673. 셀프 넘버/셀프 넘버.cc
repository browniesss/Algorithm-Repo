#include <iostream>
#include <vector>

using namespace std;

int d(int n) {
    int sum = n;
    while (n > 0) {
        sum += n % 10;  // 일의 자리 더하기
        n /= 10;        // 다음 자리로 이동
    }
    return sum;
}

int main() {
    const int LIMIT = 10000;
    vector<bool> isGenerated(LIMIT + 1, false);

    for (int i = 1; i <= LIMIT; ++i) {
        int dn = d(i);
        if (dn <= LIMIT)
            isGenerated[dn] = true;
    }

    for (int i = 1; i <= LIMIT; ++i) {
        if (!isGenerated[i])
            cout << i << '\n';
    }

    return 0;
}
