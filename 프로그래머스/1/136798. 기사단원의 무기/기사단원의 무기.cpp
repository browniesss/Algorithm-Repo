#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1;i<=number;i++)
    {
        int value = 0;
        for(int k = 1;k * k<=i;k++)
        {
            if(i % k == 0)
            {
                value++;
                if(k * k < i)
                    value++;
                
                if(value > limit)
                {
                    value = power;
                    break;
                }
            }
        }
        answer += value;
    }
    
    return answer; 
}