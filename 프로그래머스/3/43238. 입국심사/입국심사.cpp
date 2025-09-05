#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long end;
sort(times.begin(), times.end());

end = (long long)times.back() * n; // 나올 수 있는 최대 시간 구하기
long long answer = end;
long long start = 1, mid = end / 2;

while (start <= end)
{
    mid = start + (end - start) / 2;
    long long cnt = 0;
    for (int i = 0; i < times.size(); i++)
    {
        cnt += mid / times[i];
            if (cnt >= n) break;
    }

    if (cnt >= n)
    {
        answer = mid;
        end = mid - 1;
    }
    else
    {
        start = mid + 1;
    }
    }

    return answer;
}
