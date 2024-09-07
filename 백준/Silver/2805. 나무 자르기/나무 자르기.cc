#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
    int n = 0, m = 0, answer = 0;
    long long start = 1;
    long long end = -1;
    long long mid;

    cin >> n >> m;

    vector<long long> trees(n);
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end());
    end = trees.back();

    while (start <= end)
    {
        long long sum = 0;
        mid = (start + end) / 2;

        for (int i = 0; i < trees.size(); i++)
        {
            if (trees[i] - mid > 0)
            {
                sum += trees[i] - mid;
            }
        }

        if (sum >= m)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        if (mid <= end)
        {
            answer = mid;
        }
    }

    cout << answer;

    return 0;
}