#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    vector<int> targets(M);

    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    for (int i = 0; i < M; ++i) {
        cin >> targets[i];
    }

    int operations = 0;

    for (int i = 0; i < M; ++i) {
        int target = targets[i];
        int idx = 0;

        for (int j = 0; j < dq.size(); ++j) {
            if (dq[j] == target) {
                idx = j;
                break;
            }
        }

        if (idx <= dq.size() / 2) {
            while (dq.front() != target) {
                dq.push_back(dq.front());
                dq.pop_front();
                ++operations;
            }
        } else {
            while (dq.front() != target) {
                dq.push_front(dq.back());
                dq.pop_back();
                ++operations;
            }
        }

        dq.pop_front();
    }

    cout << operations << '\n';
    return 0;
}
