#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    vector<int> dp_up(N, 1);    // i번째까지 증가 or 같은 수열의 길이
    vector<int> dp_down(N, 1);  // i번째까지 감소 or 같은 수열의 길이

    int maxLen = 1;

    for (int i = 1; i < N; ++i) {
        if (arr[i] >= arr[i - 1])
            dp_up[i] = dp_up[i - 1] + 1;
        if (arr[i] <= arr[i - 1])
            dp_down[i] = dp_down[i - 1] + 1;

        maxLen = max({maxLen, dp_up[i], dp_down[i]});
    }

    cout << maxLen << '\n';
    return 0;
}
