#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    vector<vector<int>> board(102, vector<int>(102));
    queue<pair<int, int>> q;

    int x1, y1, x2, y2;

    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = 0; j < rectangle[0].size(); j++)
        {
            rectangle[i][j] *= 2;
        }

        x1 = rectangle[i][0]; y1 = rectangle[i][1];
        x2 = rectangle[i][2]; y2 = rectangle[i][3];

        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                board[y][x] = 1;
    }

    for (int i = 0; i < rectangle.size(); i++)
    {
        x1 = rectangle[i][0]; y1 = rectangle[i][1];
        x2 = rectangle[i][2]; y2 = rectangle[i][3];

        for (int y = y1 + 1; y < y2; y++)
            for (int x = x1 + 1; x < x2; x++)
                board[y][x] = 0;
    }

    q.push(make_pair(characterX, characterY));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (y == itemY && x == itemX)
            break;

        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (board[yy][xx] == 1) {
                q.push(make_pair(xx, yy));
                board[yy][xx] = board[y][x] + 1;
            }
        }
    }

    answer = board[itemY][itemX] / 2;

    return answer;
}