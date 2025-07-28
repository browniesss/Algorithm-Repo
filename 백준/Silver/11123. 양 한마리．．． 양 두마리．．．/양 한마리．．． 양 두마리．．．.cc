#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<string> map;
vector<vector<bool>> visited;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0 ,1 };
int countR = 0;
int h, w;


void DFS(int x, int y)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];

        if (xx < 0 || xx >= w || yy < 0 || yy >= h)
            continue;

        if (map[yy][xx] == '#' && !visited[yy][xx])
        {
            DFS(xx, yy);
        }
    }
}


int main()
{
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        cin >> h >> w;
        countR = 0;

        visited.clear();
        visited.resize(h, vector<bool>(w));
        map.clear();
        map.resize(h);

        for (int i = 0; i < h; i++)
        {
            cin >> map[i];
        }

        for (int i = 0; i < h; i++)
        {
            for (int k = 0; k < w; k++)
            {
                if (map[i][k] == '#' && !visited[i][k])
                {
                    countR++;
                    DFS(k, i);
                }
            }
        }

        cout << countR << '\n';
    }

    return 0;
}