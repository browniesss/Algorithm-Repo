#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> dp(500, vector<int>(500));

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < size; i++)
    {
        for (int k = 0; k < triangle[i].size(); k++)
        {
            if (k == 0)
            {
                dp[i][k] = dp[i - 1][k] + triangle[i][k];
            }
            else if (k == triangle[i].size() - 1)
            {
                dp[i][k] = dp[i - 1][k - 1] + triangle[i][k];
            }
            else
            {
                dp[i][k] = max(dp[i - 1][k - 1], dp[i - 1][k]) + triangle[i][k];
            }
        }
    }

    for (int i = 0; i < dp[size].size(); i++)
    {
        answer = max(answer, dp[size - 1][i]);
    }

    return answer;
}