#include <string>
#include <vector>
#include <iostream>

using namespace std;

int timeToMinutes(int time) {
    return (time / 100) * 60 + (time % 100);
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();
    
    for (int i = 0; i < n; i++)
    {
        bool isReward = true;
        for (int k = 0; k < 7; k++)
        {
            int day = (startday + k - 1) % 7 + 1; // 요일 계산: 1 ~ 7

            if (day == 6 || day == 7) continue; // 토, 일은 무시
            
            int latest = timeToMinutes(schedules[i]) + 10;
            int actual = timeToMinutes(timelogs[i][k]);
            
            if (actual > latest) {
                isReward = false;
                break;
            }
        }
        
        if (isReward)
        {
            answer++;
        }
    }
    cout << "answer : " << answer;
    return answer;
}