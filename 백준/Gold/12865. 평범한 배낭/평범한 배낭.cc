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

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;

        
        for (int p = k; p >= w; p--)
        {
            dp[p] = max(dp[p], dp[p - w] + v);
        }
    }

    cout << dp[k] << '\n';
    return 0;
}