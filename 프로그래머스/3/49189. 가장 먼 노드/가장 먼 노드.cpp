#include <string>
#include <vector>

using namespace std;

vector<int> ans;
vector<bool> visit;
vector<vector<int>> map;

void DFS(int start, int count)
{
    ans[start] = min(ans[start], count);

    for (int i = 0; i < map[start].size(); i++)
    {
        int val = map[start][i];
        
        if (visit[val] || ans[val] <= count + 1)
            continue;

        visit[val] = true;
        DFS(val, count + 1);
        visit[val] = false;
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxVal = -1;

    ans.resize(n + 1, 99999);
    visit.resize(n + 1);
    map.resize(n + 1);

    for (int i = 0; i < edge.size(); i++)
    {
        int start = edge[i][0];
        int end = edge[i][1];

        map[start].push_back(end);
        map[end].push_back(start);
    }

    for (int i = 0; i < map[1].size(); i++)
    {
        visit[1] = true;
        DFS(map[1][i], 1);
        visit[1] = false;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] != 99999)
            maxVal = max(maxVal, ans[i]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (maxVal == ans[i])
        {
            answer++;
        }
    }

    return answer;
}