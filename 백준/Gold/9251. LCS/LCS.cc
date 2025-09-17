#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int n = A.size();
    int m = B.size();

    // dp[i][j] = A[0..i-1], B[0..j-1] 의 LCS 길이
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                // 문자가 같으면 대각선 값 + 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // 다르면 위 또는 왼쪽 중 큰 값
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << "\n";
}
