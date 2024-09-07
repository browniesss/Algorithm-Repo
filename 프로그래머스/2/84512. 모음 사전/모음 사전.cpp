#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector<char> alphabet({ 'A','E','I','O','U' });
int cnt = 0;
int answer = -1;

void DFS(string current, string to)
{
    if (cnt == answer)
    {
        return;
    }

    for (int i = 0; i < alphabet.size(); i++)
    {
        current += alphabet[i];
        cnt++;
        if (current == to)
        {
            answer = cnt;
            return;
        }
        
        if (current.length() < 5)
            DFS(current, to);
        current.pop_back();
    }
}

int solution(string word) {
    DFS("", word);
    return answer;
}