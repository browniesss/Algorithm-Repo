#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, answer = 0;
    int min_val = 0;
    int max_val = 0;
    cin >> n >> m;

    vector<int> map;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        map.push_back(val);

        max_val += val;
        min_val = max(min_val, val);
    }

    int left = min_val;
    int right = max_val;

    while (left <= right)
    {
        int mid = (left + right) * 0.5;
        int cnt = 1;
        int temp = 0;

        for (int i = 0; i < n; i++)
        {
            if (temp + map[i] > mid)
            {
                cnt++;
                temp = map[i];
            }
            else
            {
                temp += map[i];
            }
        }

        if (cnt <= m)
        {
            right = mid - 1;
            answer = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}