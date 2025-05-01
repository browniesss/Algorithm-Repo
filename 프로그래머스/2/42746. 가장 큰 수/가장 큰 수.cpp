#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNums;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        strNums.push_back(to_string(numbers[i]));
    }

    sort(strNums.begin(), strNums.end(), compare);
    
    if (strNums[0] == "0") return "0";

    for (int i = 0; i < strNums.size(); i++)
    {
        answer += strNums[i];
    }
    
    return answer;
}