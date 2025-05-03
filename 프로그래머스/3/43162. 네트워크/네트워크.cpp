#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[201];

void DFS(vector<vector<int>> computers, int index)
{
    bool isEnd = true;
    for (int i = 0; i < computers.size(); i++)
    {
        if (visited[i])
        {
            continue;
        }
        
        if (computers[index][i] == 1)
        {
            visited[i] = true;
            DFS(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < computers.size(); i++)
    {
        if (visited[i])
        {
            continue;
        }
        
        visited[i] = true;
        DFS(computers, i);
        answer++;
    }
    
    return answer;
}