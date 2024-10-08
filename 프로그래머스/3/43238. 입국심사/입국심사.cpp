#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    // 이분 탐색 세팅
    long long start = 1;
    long long end = (long long)times[times.size() - 1] * n;
    long long mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        long long cnt = 0;

        for (int i = 0; i < times.size(); i++)
        {
            cnt += mid / times[i];
        }

        if (cnt < n)
        {
            start = mid + 1;
        }
        else
        {
            if (mid <= end)
            {
                answer = mid;
            }
            end = mid - 1;
        }
    }

    return answer;
}
