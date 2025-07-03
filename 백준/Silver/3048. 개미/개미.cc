#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Ant {
    char name;
    int dir; // 1: 오른쪽, -1: 왼쪽
};

int main() {
    int n1, n2, T;
    cin >> n1 >> n2;
    
    string group1, group2;
    cin >> group1 >> group2;
    cin >> T;

    string init = group1;
    reverse(init.begin(), init.end()); // 반대로 이동하니까 뒤집기
    init += group2;

    // 초기 개미 상태 설정
    int total = n1 + n2;
    Ant ants[100]; // 최대 50 + 50
    for (int i = 0; i < n1; ++i)
        ants[i] = { init[i], 1 }; // 오른쪽 이동
    for (int i = n1; i < total; ++i)
        ants[i] = { init[i], -1 }; // 왼쪽 이동

    // T초 동안 시뮬레이션
    while (T--) {
        int i = 0;
        while (i < total - 1) {
            // 서로 마주보는 경우 (-> <-)
            if (ants[i].dir == 1 && ants[i + 1].dir == -1) {
                swap(ants[i], ants[i + 1]);
                i += 2; // 한번에 두 개미가 점프하므로 다음은 두 칸 뒤
            } else {
                i += 1;
            }
        }
    }

    // 출력
    for (int i = 0; i < total; ++i)
        cout << ants[i].name;
    cout << '\n';

    return 0;
}
