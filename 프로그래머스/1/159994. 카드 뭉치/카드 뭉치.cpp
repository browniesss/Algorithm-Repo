#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";

    int index1 = 0;
    int index2 = 0;

    for (int i = 0; i < goal.size(); i++)
    {
        string str = goal[i]; 

        if (cards1[index1] == str)
        {
            index1++;
        }
        else if (cards2[index2] == str)
        {
            index2++;
        }
        else
        {
            answer = "No";
            break;
        }
    }

    return answer;
}