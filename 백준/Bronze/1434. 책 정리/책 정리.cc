#include<iostream>

using namespace std;

int main()
{
    int n, m;
    int a[1001] = { 0, }, b[1001] = { 0, };
    int index = 0, sum = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (a[index] >= b[i])
        {
            a[index] -= b[i];
        }
        else
        {
            index++;
            i--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    cout << sum << '\n';

    return 0;
}