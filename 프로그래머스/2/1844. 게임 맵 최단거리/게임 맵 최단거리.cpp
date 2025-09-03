#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;

bool visit[104][104];
int dist[104][104];
int dx[4] = { 0, 1 ,0, -1 };
int dy[4] = { 1, 0 ,-1, 0 };
queue<pair<int, int>> q;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();

    memset(dist, -1, sizeof(dist));

    q.push({ 0,0 });
    visit[0][0] = 1;
    dist[0][0] = 1;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.first == n - 1 && cur.second == m - 1)
        {
            return dist[n - 1][m - 1];
        }

        for (int i = 0; i < 4; i++)
        {
            int xx = cur.second + dx[i];
            int yy = cur.first + dy[i];

            if (xx < 0 || yy < 0 || xx >= m || yy >= n)
            {
                continue;
            }

            if (visit[yy][xx] || maps[yy][xx] == 0 || dist[yy][xx] != -1)
            {
                continue;
            }

            q.push({ yy,xx });
            visit[yy][xx] = true;
            dist[yy][xx] = dist[cur.first][cur.second] + 1;
        }
    }

    answer = dist[n - 1][m - 1];

    return answer;
}
