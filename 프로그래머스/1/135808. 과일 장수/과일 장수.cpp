#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<int>());
    
    for (int i = 0; i + m <= score.size(); i += m) 
    {
        int minScore = score[i + m - 1]; 
        answer += minScore * m;
    }
    
    return answer;
}