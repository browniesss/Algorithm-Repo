#include <string>
#include <vector>

using namespace std;

bool visit[200];
void DFS(int current, int n, vector<vector<int>> computers)
{
    visit[current] = true;

    for (int i = 0; i < n; i++)
    {
        if (!visit[i] && computers[current][i] == 1)
        {
            DFS(i, n, computers);
        }
    }

    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            DFS(i, n, computers);
            
            answer++;
        }
    }

    return answer;
}