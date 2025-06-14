#include <string>
#include <vector>

using namespace std;
bool isValid(const string& s) {
    vector<string> sounds = {"aya", "ye", "woo", "ma"};
    int i = 0;
    string prev = "";

    while (i < s.size()) {
        bool matched = false;
        for (const string& sound : sounds) {
            if (s.substr(i, sound.size()) == sound && sound != prev) {
                prev = sound;
                i += sound.size();
                matched = true;
                break;
            }
        }
        if (!matched) return false;
    }
    return true;
}
        
int solution(vector<string> babbling) {
    int answer = 0;
    for (const string& word : babbling) {
        if (isValid(word)) {
            answer++;
        }
    }
    
    return answer;
}