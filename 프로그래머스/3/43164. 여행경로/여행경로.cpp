#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

bool visit[10000];
vector<string> temp;
bool isAnswer = false;

void DFS(string current, vector<vector<string>> tickets, int count)
{
    temp.push_back(current);


    if (count == tickets.size())
    {
        isAnswer = true;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (visit[i])
        {
            continue;
        }

        if (current == tickets[i][0])
        {
            visit[i] = true;
            
            DFS(tickets[i][1], tickets, count + 1);

            if (!isAnswer)
            {
                temp.pop_back();
                visit[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());

    DFS("ICN", tickets, 0);
    answer = temp;

    return answer;
}