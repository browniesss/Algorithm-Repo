#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int q = 0; q < targets.size(); q++)
    {
        bool flag = false;
        int sum = 0;
        
        for (int i = 0; i < targets[q].size(); i++)
        {
            char targetAlphabet = targets[q][i];
            int minIndex = 1000;
            for (int k = 0; k < keymap.size(); k++)
            {
                for (int j = 0; j < keymap[k].size(); j++)
                {
                    if (targetAlphabet == keymap[k][j])
                    {
                        minIndex = min(minIndex, j + 1);
                    }
                }
            }
            
            if (minIndex != 1000)
            {
                sum += minIndex;   
            }
            else
            {
                answer.push_back(-1);
                flag = true;
                break;
            }
        }
        
        if (!flag)
            answer.push_back(sum);
    }
    
    return answer;
}