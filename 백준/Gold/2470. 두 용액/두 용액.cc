#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int cur = 2000000001;

bool set_cur(int next)
{
    int cur_val = 0 - cur;
    int next_val = 0 - next;

    cur_val = abs(cur_val);
    next_val = abs(next_val);

    cur = min(cur_val, next_val);

    return cur_val > next_val ? true : false; // true : 값 변경, false : 값 유지
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> map(n);
    pair<int, int> answer; 
    
    int left = 0;
    int right = n - 1;

    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
    sort(map.begin(), map.end());

    // -99 -2 -1 4 98
    while (left < right)
    {
        int val = map[left] + map[right];

        if (set_cur(val))
        {
            answer.first = map[left];
            answer.second = map[right];
        }

        if (val < 0)
        {
            left++;

        }
        else if (val > 0)
        {
            right--;
        }
        
        if(val == 0)
        {
            break;
        }
    }

    cout << answer.first << " " << answer.second << '\n';

    return 0;
}