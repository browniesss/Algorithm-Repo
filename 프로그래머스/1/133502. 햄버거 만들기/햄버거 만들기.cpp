#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    vector<int> stack;
    int answer = 0;

    for (int i : ingredient) {
        stack.push_back(i);

        // 스택 크기가 최소 4 이상이어야 햄버거 만들 수 있음
        if (stack.size() >= 4) {
            int n = stack.size();
            if (stack[n - 4] == 1 &&
                stack[n - 3] == 2 &&
                stack[n - 2] == 3 &&
                stack[n - 1] == 1) {
                // 햄버거 포장 후 재료 제거
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                answer++;
            }
        }
    }

    return answer;
}