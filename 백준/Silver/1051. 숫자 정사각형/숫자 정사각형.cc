#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    int maxSize = 1;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            for (int d = 1; r + d < N && c + d < M; ++d) {
                // 네 꼭짓점의 값이 같은지 확인
                if (grid[r][c] == grid[r][c + d] &&
                    grid[r][c] == grid[r + d][c] &&
                    grid[r][c] == grid[r + d][c + d]) {
                    int size = (d + 1) * (d + 1);
                    maxSize = max(maxSize, size);
                }
            }
        }
    }

    cout << maxSize << endl;
    return 0;
}
