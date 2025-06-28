#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vec;
vector<vector<bool>> visited;
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
int n, m;
bool flag = false;

void DFS(int x, int y)
{
    if (x == n - 1 && y == m - 1)
    {
        flag = true;
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx < 0 || xx >= n || yy < 0 || yy >= m)
            continue;

        if (vec[yy][xx] == 0 || visited[yy][xx])
            continue;

        visited[yy][xx] = true;
        DFS(xx, yy);
    }

    return;
}

int main()
{
    cin >> n >> m;

    vec.resize(m, vector<int>(n));
    visited.resize(m, vector<bool>(n));

    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cin >> vec[i][k];
        }
    }

    visited[0][0] = true;
    DFS(0, 0);

    if (flag)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}