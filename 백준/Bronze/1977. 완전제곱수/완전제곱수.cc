#include <iostream>
using namespace std;
int main() {
    int min = 10001, m,n;
    int sum = 0, cnt=0;
    
    cin >> m >> n;
    
    for (int j = 1; j <= 100; j++)
    {
        if(j*j >= m && j*j <= n)
        {
            sum += j*j;
            cnt++;
        }
        if (j*j >= m && j*j <= n && min > j*j)
        {
            min = j*j;
        }
    }
    if (cnt == 0)
    {
        cout << "-1";
        return 0;
    }
    cout << sum << '\n' << min;
}