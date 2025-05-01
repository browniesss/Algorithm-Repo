#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) 
{
    int answer = 0;
    int number = num - 1;
    int target_row = number / w;
    int target_col = 0;

    if (target_row % 2 == 0) 
    {
        // 짝수층: 왼쪽 -> 오른쪽
        target_col = number % w;
    } else 
    {
        // 홀수층: 오른쪽 -> 왼쪽
        target_col = w - 1 - number % w;
    }

    for (int r = target_row + 1; ; r++) 
    {
        int boxIndex = r * w + 1;
        if (boxIndex > n) 
        {
            break;
        }
        
        // r층이 짝수면 왼쪽 → 오른쪽, 홀수면 오른쪽 → 왼쪽
        int col_in_layer = (r % 2 == 0) ? target_col : (w - 1 - target_col);
        int box_number = r * w + col_in_layer + 1;

        if (box_number <= n) 
        {
            answer++;
        }
        else break;
    }
     
    return answer + 1;
}