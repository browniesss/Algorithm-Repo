#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 5;
const int dx[4] = { -1, 1, 0, 0 }; // 상하좌우 이동
const int dy[4] = { 0, 0, -1, 1 };

vector<vector<int>> board(N, vector<int>(N));
set<string> unique_numbers;

void dfs(int x, int y, string current, int depth) {
    if (depth == 6) {
        unique_numbers.insert(current);
        return;
    }
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
            dfs(nx, ny, current + to_string(board[nx][ny]), depth + 1);
        }
    }
}

int main() {
    // 입력 받기
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    // 모든 위치에서 DFS 시작
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dfs(i, j, to_string(board[i][j]), 1);
        }
    }

    // 서로 다른 6자리 수의 개수 출력
    cout << unique_numbers.size() << endl;

    return 0;
}
