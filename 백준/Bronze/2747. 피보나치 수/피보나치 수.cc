#include<iostream>

using namespace std;

int main()
{
    int n, dp[46] = { 0, };
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];

    return 0;
}