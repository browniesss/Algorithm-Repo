#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    int maxVal = -1;
    cin >> n >> k;

    vector<int> vec(n * 2);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> vec[i];

        vec[i + n] = vec[i];
    }

    int val = 0;
    for (int i = 0; i < k; i++)
    {
        val += vec[i];
    }
    maxVal = val;

    for (int i = 1; i < n; i++)
    {
        val -= vec[i - 1];
        val += vec[i + k - 1];

        maxVal = max(maxVal, val);
    }

    cout << maxVal << "\n";
    return 0;
}