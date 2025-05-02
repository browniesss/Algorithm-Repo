#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for (int i = 0; i < photo.size(); i++)
    {
        int score = 0;
        for(int k =0; k < photo[i].size(); k++)
        {
            for(int j = 0; j < name.size(); j++)
            {
                if(photo[i][k] == name[j])
                {
                    score += yearning[j];    
                }
            }
        }
        
        answer.push_back(score);
    }
    return answer;
}