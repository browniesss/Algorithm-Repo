#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;
bool visit[100001] = { false, };
int result[100001] = { 0, };
int order = 1;

void DFS(int start)
{
    visit[start] = true;
    result[start] = order++;

    for (int i = 0; i < map[start].size(); i++)
    {
        int val = map[start][i];

        if (!visit[val])
        {
            DFS(val);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    
    map.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        map[a].push_back(b);
        map[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(map[i].begin(), map[i].end());
    }

    DFS(r);
    
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}