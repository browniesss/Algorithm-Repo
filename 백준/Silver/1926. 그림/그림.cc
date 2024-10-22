#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visit[501][501] = { false, };
vector<vector<int>> map;
int max_val = 0;
int cnt = 0, n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int DFS(int x, int y)
{
    int area = 1;

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx < 0 || xx >= m || yy < 0 || yy >= n)
            continue;

        if (!visit[yy][xx] && map[yy][xx] == 1)
        {
            visit[yy][xx] = true;
            area += DFS(xx, yy);
        }
    }

    return area;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    map.resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            int val;
            cin >> val;

            map[i].push_back(val);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (!visit[i][k] && map[i][k] == 1)
            {
                visit[i][k] = true;
                max_val = max(DFS(k, i), max_val);
                cnt++;
            }
        }
    }

    cout << cnt << '\n' << max_val << '\n';

    return 0;
}