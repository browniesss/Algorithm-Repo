#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

vector<int> m[200];

int DFS(int togo, int now, int cnt)
{
    for (int i = 0; i < m[now].size(); i++)
    {
        // ex: 2번이라 치면, 2번에 연결된 노드들을 다 검사해서, 현재 내가 보낸 노드 제외하고 연결된 모든 카운트를 반환.
        if (m[now][i] != togo)
        {
            cnt = DFS(now, m[now][i], cnt + 1);
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for (auto w : wires)
    {
        // 실제로 노드를 연결
        // ex: 2번 노드의 경우 아래 코드를 통해 2번 노드에 연결된 모든 노드들이 연결됨.
        m[w[0]].push_back(w[1]);
        m[w[1]].push_back(w[0]);
    }

    for (auto w : wires)
    {
        int sum = DFS(w[0], w[1], 1);
        int comp = abs(sum - (n - sum));
        answer = min(answer, abs(comp));
    }
    

    return answer;
}