#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, H;
    cin >> N >> H;

    vector<int> bottom(H + 1, 0); // 석순(아래에서 올라오는 장애물)
    vector<int> top(H + 1, 0);    // 종유석(위에서 내려오는 장애물)

    // 입력을 석순과 종유석에 나눠서 받기
    for (int i = 0; i < N; i++) {
        int height;
        cin >> height;
        if (i % 2 == 0) {
            bottom[height]++; // 짝수 인덱스는 석순
        } else {
            top[height]++;    // 홀수 인덱스는 종유석
        }
    }

    // 석순과 종유석의 누적합 계산 (구간별 장애물 수 계산)
    for (int i = H - 1; i >= 1; i--) {
        bottom[i] += bottom[i + 1]; // 석순은 위에서부터 누적
        top[i] += top[i + 1];       // 종유석은 아래에서부터 누적
    }

    int min_obstacles = N;  // 최소 장애물 수
    int count = 0;          // 최소 장애물 수를 갖는 구간의 수

    // 각 높이별로 석순과 종유석에 부딪히는 장애물 수 계산
    for (int i = 1; i <= H; i++) {
        int obstacles = bottom[i] + top[H - i + 1]; // i 높이에서의 장애물 수

        if (obstacles < min_obstacles) {
            min_obstacles = obstacles;
            count = 1;  // 새로운 최소 장애물 수가 발견되면 초기화
        } else if (obstacles == min_obstacles) {
            count++;    // 최소 장애물 수와 같은 구간의 수 증가
        }
    }

    cout << min_obstacles << " " << count << '\n';

    return 0;
}
