#include <string>
#include <vector>

using namespace std;

int result = 0;

void DFS(vector<int> numbers, int sum, int target, int depth, int len)
{
    if (sum == target && depth == len)
    {
        result++;

        return;
    }
    else if (depth == len)
    {
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        int sign = i % 2 == 0 ? 1 : -1;
        int val = numbers[depth] * sign;

        DFS(numbers, sum + val, target, depth + 1, len);
    }
    
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(numbers, 0, target, 0, numbers.size());
    answer = result;

    return answer;
}