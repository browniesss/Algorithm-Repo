#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0 ,1 };
int countR = 0;
int dp[1001] = { -1, };


int main()
{
    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[3] = 1;
    dp[4] = 1;

    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        if (dp[i] == 1)
        {
            continue;
        }

        if (i > 1 && dp[i - 1] == 1)
        {
            flag++;
        }
        
        if (i > 3 && dp[i - 3] == 1)
        {
            flag++;
        }

        if (i > 4 && dp[i - 4] == 1)
        {
            flag++;
        }

        if (flag < 3 && (i > 1 && dp[i - 1] == 0) || (i > 3 && dp[i - 3] == 0) || (i > 4 && dp[i - 4] == 0))
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 0;
        }
    }

    if (dp[n] == 0)
    {
        cout << "CY" << "\n";
    }
    else
    {
        cout << "SK" << "\n";
    }
    return 0;
}