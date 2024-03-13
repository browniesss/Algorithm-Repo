#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    
    while (N--)
    {
        int aN, bN;
        int a, b;
        int A[5] = {0}, B[5] = {0};
        int count = 0;
        
        cin >> aN;
        for (int i = 0; i < aN; i++) {
            cin >> a;  
            A[a]++;    
        }
        cin >> bN;
        for (int i = 0; i < bN; i++) {
            cin >> b;
            B[b]++;
        }
        
        for (int i = 4; i > 0; i--) {
            if (A[i] > B[i]) {
                cout << "A\n";
                break;
            }
            else if (A[i] < B[i]) {
                cout << "B\n";
                break;
            }
            else count++;  
        }
        if (count == 4) cout << "D\n";
    }
}