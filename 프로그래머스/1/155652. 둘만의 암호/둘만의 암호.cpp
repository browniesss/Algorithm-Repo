#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        int tempIdx = 0;
        int idx = 0;
        
        while (idx != index)
        {
            bool flag = false;
            tempIdx++;
            char temp = (c - 'a' + tempIdx) % 26 + 'a';
            
            for (int k = 0; k < skip.size(); k++)
            {
                if (temp == skip[k])
                    flag = true;
            }
            
            if (!flag)
                idx++;
        }
        
        char finalChar = (c - 'a' + tempIdx) % 26 + 'a';
        answer.push_back(finalChar);
    }
    
    return answer;
}