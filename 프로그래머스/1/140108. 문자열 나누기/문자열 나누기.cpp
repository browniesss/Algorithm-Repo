#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i = 0;
    int n = s.size();

    while (i < n) {
        char x = s[i];
        int countX = 0;
        int countOther = 0;
        int j = i;

        while (j < n) {
            if (s[j] == x) countX++;
            else countOther++;

            j++;

            if (countX == countOther) break;
        }

        answer++;
        i = j; // 다음 분해 시작 지점으로 이동
    }
    return answer;
}