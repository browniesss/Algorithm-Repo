#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> map;
    vector<string> answer;
    
    for (int i = 0; i < players.size(); i++)
    {
        map[players[i]] = i;
    }
    
    for (const string& name : callings) {
        int idx = map[name];     // 현재 등수
        int front = idx - 1;             // 앞 선수의 등수

        // 선수 swap
        swap(players[front], players[idx]);

        // 인덱스 업데이트
        map[players[front]] = front;
        map[players[idx]] = idx;
    }
    
    answer = players;
    
    return answer;
}