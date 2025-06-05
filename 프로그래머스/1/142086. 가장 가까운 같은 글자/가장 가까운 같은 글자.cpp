#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int temp[100] = {0,};
    
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        
        if (temp[c - 'a'] == 0)
        {
            temp[c - 'a'] = i + 1;
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - temp[c - 'a'] + 1);
            temp[c - 'a'] = i + 1;
        }
    }
    
    
    return answer;
}