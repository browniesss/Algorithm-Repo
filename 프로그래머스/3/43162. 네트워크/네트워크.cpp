#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int minCount = 999999;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> map;
vector<bool> visited;

void DFS(int index, vector<vector<int>> map)
{
    for (int i = 0; i < map[index].size(); i++)
    {
        if (visited[i])
            continue;

        if (map[index][i] == 1)
        {
            visited[i] = true;
            DFS(i, map);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(computers.size());

    for (int i = 0; i < computers.size(); i++)
    {
        if (visited[i])
            continue;

        answer++;
        visited[i] = true;
        DFS(i, computers);
    }

    return answer;
}
