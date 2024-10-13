#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<int> result;
bool visit[100001];

int cnt = 1;

void DFS(int start)
{
    visit[start] = true;
    result[start] = cnt++;

    for (int i = 0; i < map[start].size(); i++)
    {
        int to = map[start][i];

        if (!visit[to])
        {
            DFS(to);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    map.resize(n + 1);
    result.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        map[a].push_back(b);
        map[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
    {
        sort(map[i].begin(), map[i].end(), greater<int>());
    }

    DFS(r);

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}