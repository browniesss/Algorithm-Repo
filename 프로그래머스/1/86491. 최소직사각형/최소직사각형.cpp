#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxW = 0, maxH = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        int temp = sizes[i][0];

        if (sizes[i][0] < sizes[i][1])
        {
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }

        maxW = max(maxW, sizes[i][0]);
        maxH = max(maxH, sizes[i][1]);
    }

    answer = maxW * maxH;

    return answer;
}