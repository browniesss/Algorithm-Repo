#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int luX = 51, luY = 51;
    int rdX = 0, rdY = 0;
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for (int k = 0; k < wallpaper[i].size(); k++)
        {
            auto value = wallpaper[i][k];
            
            if (value == '#')
            {
                luX = min(luX, k);
                rdX = max(rdX, k + 1);
                
                luY = min(luY, i);
                rdY = max(rdY, i + 1);
            }
        }
    }
    
    answer.push_back(luY);
    answer.push_back(luX);
    answer.push_back(rdY);
    answer.push_back(rdX);
    return answer;
}