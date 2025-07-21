#include <iostream>
using namespace std;

int main() {
    long long N;
    int L;
    cin >> N >> L;

    for (int len = L; len <= 100; len++) 
    {
        long long tmp = (long long)(len - 1) * len / 2;

        if (N - tmp < 0) break; 

        if ((N - tmp) % len == 0) 
        {
            long long x = (N - tmp) / len;
            for (int i = 0; i < len; i++) 
            {
                cout << x + i << " ";
            }
            return 0;
        }
    }

    cout << -1;
    return 0;
}
