#include <iostream>
using namespace std;

int main()
{
    int N, one, two, ball = 1;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> one >> two;
        if (one == ball)
        {
            ball = two;
        }
        else if (two == ball)
        {
            ball = one;
        }
    }
    cout << ball;
    return 0;
}