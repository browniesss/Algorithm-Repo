#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0 ,1 };
int countR = 0;


void DFS(int x, int y, int count, int moveCount)
{
    visited[y][x] = true;
    if (map[y][x] == 1)
    {
        count++;

        if (count >= 2 && moveCount <= 3)
        {
            countR = 1;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];

        if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5)
            continue;

        if (map[yy][xx] != -1 && !visited[yy][xx])
        {
            int temp = map[y][x];

            map[y][x] = -1;
            visited[yy][xx] = true;
            DFS(xx, yy, count, moveCount + 1);
            visited[yy][xx] = false;
            map[y][x] = temp;
        }
    }
}


int main()
{
    visited.clear();
    visited.resize(5, vector<bool>(5));
    map.clear();
    map.resize(5, vector<int>(5));

    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            cin >> map[i][k];
        }
    }

    int r, c;

    cin >> r >> c;

    //visited[r][c] = true;
    DFS(c, r, 0, 0);

    cout << countR << "\n";
    return 0;
}