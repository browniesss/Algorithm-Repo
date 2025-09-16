#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<string> heard;
    heard.reserve(static_cast<size_t>(N) * 2); // 리해시 최소화
    heard.max_load_factor(0.7f);

    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        heard.insert(name);
    }

    vector<string> both;
    both.reserve(min(N, M)); // 대략적인 상한

    for (int i = 0; i < M; ++i) {
        string name;
        cin >> name;
        if (heard.find(name) != heard.end()) {
            both.push_back(name);
        }
    }

    sort(both.begin(), both.end()); // 사전순 요구
    cout << both.size() << '\n';
    for (size_t i = 0; i < both.size(); ++i) {
        cout << both[i] << '\n';
    }
    return 0;
}
