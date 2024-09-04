#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int arrB[8] = { 2,1,2,3,2,4,2,5 };
    int arrC[10] = { 3,3,1,1,2,2,4,4,5,5 };
    int user[3] = { 0, };
    int maxx = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if ((i % 5) + 1 == answers[i])
        {
            user[0]++;
        }
        
        if (arrB[i % 8] == answers[i])
        {
            user[1]++;
        }

        if (arrC[i % 10] == answers[i])
        {
            user[2]++;
        }
    }

    maxx = max({ user[0], user[1], user[2] });
    for (int i = 0; i < 3; i++)
    {
        if (maxx == user[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}