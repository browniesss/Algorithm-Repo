#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<int> map(n, 1);
    
    for (int i = 0; i < section.size(); i++)
    {
        map[section[i] - 1] = 0;
    }
    
    
    for (int i = 0; i < section.size(); i++)
    {
        int val = section[i] - 1;
        if (map[val] != 0)
        {
            continue;
        }
        
        for (int k = val; k < val + m && k < n; k++)
        {
            if (map[k] == 0)
            {
                map[k] = 1;
            }
        }
        
        answer++;
    }
    
    return answer;
}