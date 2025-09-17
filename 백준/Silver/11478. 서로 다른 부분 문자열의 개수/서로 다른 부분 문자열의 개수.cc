#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_set<string> set;

    for (int i = 0; i < s.size(); i++)
    {
        string val;

        val.push_back(s[i]);
        set.insert(val);
        for (int k = i + 1; k < s.size(); k++)
        {
            val.push_back(s[k]);
            set.insert(val);
        }
    }

    cout << set.size() << "\n";
    return 0;
}