#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    
    do
    {
        int temp = k;
        int cnt = 0;

        for (int i = 0; i < dungeons.size(); i++)
        {
            int minK = dungeons[i][0];
            int useK = dungeons[i][1];

            if (temp >= minK)
            {
                temp -= useK;
                cnt++;
            }
        }

        if (cnt >= answer)
        {
            answer = cnt;
        }

    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}