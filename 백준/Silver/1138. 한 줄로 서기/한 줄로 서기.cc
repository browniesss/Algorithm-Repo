#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    int arr[11] = { 0, };
    cin >> N;


    for (int i = 1; i <= N; i++)
    {
        int val;
        cin >> val;

        for (int k = 0; k < N; k++)
        {
            if (val == 0 && arr[k] == 0)
            {
                arr[k] = i;
                break;
            }

            if (arr[k] == 0 || arr[k] > i)
            {
                val--;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}