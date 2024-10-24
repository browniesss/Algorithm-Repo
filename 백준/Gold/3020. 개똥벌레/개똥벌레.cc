#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, H;
    cin >> N >> H;

    vector<int> bottom(H + 1);
    vector<int> top(H + 1);

    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;

        if (i % 2 == 0)
        {
            bottom[val]++;
        }
        else
        {
            top[val]++;
        }
    }

    for (int i = H - 1; i >= 1; i--)
    {
        bottom[i] += bottom[i + 1];
        top[i] += top[i + 1];
    }

    int min_val = N;
    int count = 0;

    for (int i = 1; i <= H; i++)
    {
        int val = bottom[i] + top[H - i + 1];

        if (val < min_val)
        {
            min_val = val;
            count = 1;
        }
        else if (val == min_val)
        {
            count++;
        }
    }

    cout << min_val << ' ' << count << '\n';
    return 0;
}