#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

bool isDecimal(int val)
{
    if (val == 0 || val == 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(val); i++)
    {
        if (val % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());

    unordered_set<int> num;

    do
    {
        string temp;
        for (int i = 0; i < numbers.size(); i++)
        {
            temp += numbers[i];
            if (isDecimal(stoi(temp)))
            {
                num.insert(stoi(temp));
            }

        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    answer = num.size();

    return answer;
}
