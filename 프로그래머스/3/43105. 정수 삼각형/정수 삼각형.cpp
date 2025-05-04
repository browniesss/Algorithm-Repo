#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int height = triangle.size();

    // 아래에서부터 위로 거꾸로 누적
    for (int i = height - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            // 아래 두 칸 중 더 큰 값을 현재 값에 더함
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    // 꼭대기 값이 이제 최대 합
    return triangle[0][0];
}