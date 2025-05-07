#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> vertex) {
    vector<vector<int>> graph(n + 1);
    vector<int> distance(n + 1, 0);
    queue<int> q;

    // 인접 리스트 구성
    for (const auto& edge : vertex) {
        int a = edge[0], b = edge[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // BFS 시작
    q.push(1);
    distance[1] = 1; // 방문 표시 (0은 미방문)

    while (!q.empty()) {
        int current = q.front(); q.pop();

        for (int next : graph[current]) {
            if (distance[next] == 0) {
                distance[next] = distance[current] + 1;
                q.push(next);
            }
        }
    }

    // 최대 거리 계산
    int maxDist = *max_element(distance.begin(), distance.end());
    int count = count_if(distance.begin(), distance.end(), [maxDist](int d) 
    {
        return d == maxDist;
    });

    return count;
}