#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int originX = 0;
    int originY = 0;
    int tempX = 0;
    int tempY = 0;
    
    for (int i = 0; i < park.size(); i++) 
    {
        for (int j = 0; j < park[i].size(); j++) 
        {
            if (park[i][j] == 'S') {
                originX = i;
                originY = j;
            }
        }
    }
    
    for (int i = 0; i < routes.size(); i++)
    {
        char c = routes[i][0];
        int amount = stoi(routes[i].substr(2));
        bool canMove = true;
        
        tempX = originX;
        tempY = originY;
        
        // 방향 벡터
        int dx = 0, dy = 0;

        if (c == 'E') dy = 1;
        else if (c == 'W') dy = -1;
        else if (c == 'S') dx = 1;
        else if (c == 'N') dx = -1;
        
        for (int k = 0; k < amount; k++)
        {
            tempX += dx;
            tempY += dy;
            
            if (tempX < 0 || tempX >= park.size() || tempY < 0 || tempY >= park[0].size                () || park[tempX][tempY] == 'X')
            {
                cout << tempX << " " << tempY << " " << amount << "\n";
                canMove = false;
                break;
            }
        }
        
        if(canMove)
        {
            originX = tempX;
            originY = tempY;
        }   
    }
    
    answer.push_back(originX);
    answer.push_back(originY);
    
    return answer;
}