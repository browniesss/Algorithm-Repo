#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using Block = vector<pair<int, int>>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int n, vector<vector<int>>& board, vector<vector<bool>>& visited, Block& block, int target) {
    visited[x][y] = true;
    block.push_back({x, y});

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
            !visited[nx][ny] && board[nx][ny] == target) {
            dfs(nx, ny, n, board, visited, block, target);
        }
    }
}

Block normalize(Block& block) {
    int minX = 50, minY = 50;
    for (auto [x, y] : block) {
        minX = min(minX, x);
        minY = min(minY, y);
    }
    Block norm;
    for (auto [x, y] : block) {
        norm.push_back({x - minX, y - minY});
    }
    sort(norm.begin(), norm.end());
    return norm;
}

Block rotate90(const Block& block) {
    Block rotated;
    for (auto [x, y] : block) {
        rotated.push_back({y, -x});
    }
    return normalize(rotated);
}

bool isSameBlock(const Block& a, const Block& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    int n = game_board.size();
    vector<Block> blanks, puzzles;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // 빈칸 (0) 추출
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j] && game_board[i][j] == 0) {
                Block b;
                dfs(i, j, n, game_board, visited, b, 0);
                blanks.push_back(normalize(b));
            }

    // 퍼즐 조각 (1) 추출
    visited = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j] && table[i][j] == 1) {
                Block b;
                dfs(i, j, n, table, visited, b, 1);
                puzzles.push_back(normalize(b));
            }

    vector<bool> used(puzzles.size(), false);

    // 퍼즐 매칭
    for (auto& blank : blanks) {
        for (int i = 0; i < puzzles.size(); i++) {
            if (used[i]) continue;

            Block p = puzzles[i];
            for (int r = 0; r < 4; r++) {
                if (isSameBlock(blank, p)) {
                    answer += p.size();
                    used[i] = true;
                    break;
                }
                p = rotate90(p);
            }
            if (used[i]) break;
        }
    }
    return answer;
}