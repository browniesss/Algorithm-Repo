#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> queue;
    
    for (int s : score) {
        if (queue.size() < k) {
            queue.push(s);  // 명예의 전당이 k개보다 적으면 그냥 추가
        } else {
            if (s > queue.top()) {
                queue.pop();      // 최하위 점수 제거
                queue.push(s);    // 새 점수 추가
            }
        }
        answer.push_back(queue.top());  // 현재 최하위 점수 저장
    }
    
    return answer;
}