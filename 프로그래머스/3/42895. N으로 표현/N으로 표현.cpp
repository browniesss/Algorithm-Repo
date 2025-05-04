#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int solution(int N, int number) {
    int answer = -1;
    
    if (N == number)
    {
        return 1;
    }
    
    vector<unordered_set<int>> dp(9);

    for (int i = 0; i <= 8; i++)
    {
        int repeated = 0;
        for (int k = 0; k < i; k++)
        {
            repeated = repeated * 10 + N;
        }
        dp[i].insert(repeated);
        
        for (int k = 1; k < i; k++)
        {
            for (int a : dp[k])
            {
                for (int b : dp[i - k])
                {
                    dp[i].insert(a - b);
                    dp[i].insert(a + b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }
        
        if (dp[i].count(number))
        {
            return i;
        }
    }
    
    return answer;
}