#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        stack<char> st;

        for (int k = 0; k < str.size(); k++)
        {
            if (st.size() == 0)
            {
                st.push(str[k]);
                continue;
            }

            if (st.top() == str[k])
            {
                st.pop();
            }
            else
            {
                st.push(str[k]);
            }
        }

        if (st.size() == 0)
        {
            sum++;
        }
    }

    cout << sum;

    return 0;
}