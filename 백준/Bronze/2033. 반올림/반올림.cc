#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n,t;
    int m = 10;
    
    cin >> n;
    
    while(n > m)
    {
        t = n % m;
        n -= t;
        if(t >= 5 * (m / 10))
        {
            n += m;
        }
        m *= 10;
    }
    
    cout << n;
}