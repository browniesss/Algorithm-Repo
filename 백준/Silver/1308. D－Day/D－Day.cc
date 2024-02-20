#include <bits/stdc++.h>
using namespace std;

int days(int y, int m, int d)
{
    int result = 365 * (y - 1) + d - 1; 

    for (int i = 1; i < y; i++) if (!(i % 400) || (!(i % 4) && i % 100)) result++;

    
    for (int i = 1; i < m; i++)
    {
        if (i & 1 ^ (i >= 8))
            result += 31;
        else if (i == 2)
        {
            if (!(y % 400) || (!(y % 4) && y % 100))
                result += 29;
            else 
                result += 28;
        }
        else
            result += 30;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

    if (y2 - y1 > 1000 || (y2 - y1 == 1000 && (m1 < m2 || (m1 == m2 && d1 <= d2))))
        cout << "gg";

    else cout << "D-" << days(y2, m2, d2) - days(y1, m1, d1);
}