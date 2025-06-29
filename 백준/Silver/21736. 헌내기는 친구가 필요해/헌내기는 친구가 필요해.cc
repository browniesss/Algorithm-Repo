#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vec;
vector<vector<bool>> visited;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;
int px, py, sum = 0;

void DFS(int x, int y)
{
    if (vec[y][x] == 'P')
        sum++;

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx < 0 || xx >= m || yy < 0 || yy >= n)
            continue;

        if (vec[yy][xx] == 'X' || visited[yy][xx])
            continue;

        visited[yy][xx] = true;
        DFS(xx, yy);
    }

    return;
}

int main()
{
    cin >> n >> m;

    vec.resize(n);
    visited.resize(n, vector<bool>(m));

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        for (int k = 0; k < m; k++)
        {
            if (vec[i][k] == 'I')
            {
                px = k;
                py = i;
            }
        }
    }

    visited[py][px] = true;
    DFS(px, py);

    if (sum > 0)
    {
        cout << sum;
    }
    else
    {
        cout << "TT";
    }

    return 0;
}