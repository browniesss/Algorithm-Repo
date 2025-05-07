#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    // 이긴 관계를 기록하는 2차원 배열
    vector<vector<bool>> win(n + 1, vector<bool>(n + 1, false));

    // 주어진 경기 결과 저장
    for (const auto& result : results) {
        int winner = result[0];
        int loser = result[1];
        win[winner][loser] = true;
    }

    // 플로이드 워셜 - A가 B를 이기고 B가 C를 이기면 A가 C를 이김
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (win[i][k] && win[k][j]) {
                    win[i][j] = true;
                }
            }
        }
    }

    int answer = 0;

    // 각 선수에 대해 순위 확정 여부 판단
    for (int i = 1; i <= n; ++i) {
        int count = 0;

        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;

            if (win[i][j] || win[j][i]) {
                ++count;
            }
        }

        // n - 1명과의 관계가 확실히 드러난 경우
        if (count == n - 1) {
            ++answer;
        }
    }

    return answer;
}