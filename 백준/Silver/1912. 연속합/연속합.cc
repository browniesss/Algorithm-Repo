#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dp[100001] = { 0, };

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    int result = -1001;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> dp[i];
    }

    for (int i = 1; i < n; i++)
    {
        int val = dp[i - 1] + dp[i];
        if (dp[i] <= val)
        {
            dp[i] = val;
        }
    }

    for (int i = 0; i < n; i++)
    {
        result = max(result, dp[i]);
    }
    cout << result << '\n';

    return 0;
}