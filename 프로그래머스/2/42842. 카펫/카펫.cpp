#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    for (int i = 1; i < brown; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            if (i * k == sum && (i-2) * (k-2) == yellow)
            {
                answer.push_back(i);
                answer.push_back(k);
            }
        }
    }
    return answer;
}



// 4, 2, 3, 1
// 3, 1, 3, 1
// 8, 5, 7, 4