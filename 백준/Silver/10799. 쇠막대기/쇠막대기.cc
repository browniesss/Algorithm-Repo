#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int n = 0;
    string str;
    cin >> str;
    stack<char> st;


    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if (st.size() == 0)
        {
            st.push(c);
            continue;
        }

        if (c == ')')
        {
            st.pop();

            if (str[i - 1] == '(')
            {
                n += st.size();
            }
            else if (str[i - 1] == ')')
            {
                n += 1;
            }
        }
        else if (c == '(')
        {
            st.push(c);
        }
    }

    cout << n;

    return 0;
}