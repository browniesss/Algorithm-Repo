#include <string>
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
vector<int> map;

void DFS(int index, int curSum, int target)
{
    if (index == map.size())
    {
        if (curSum == target)
        {
            cnt++;
        }

        return;
    }

    DFS(index + 1, curSum + map[index], target);
    DFS(index + 1, curSum - map[index], target);
}

int solution(vector<int> numbers, int target) {
    map = numbers;
    DFS(0, 0, target);

    return cnt;
}
