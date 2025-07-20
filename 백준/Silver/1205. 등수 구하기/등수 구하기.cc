#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, score, P;
    cin >> N >> score >> P;

    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    int rank = 1;
    for (int i = 0; i < N; ++i) {
        if (scores[i] > score) {
            rank++;
        } else {
            break;
        }
    }

    if (N == P && (rank > P || (scores.size() >= P && scores[P - 1] >= score))) {
        cout << -1;
    } else {
        cout << rank;
    }

    return 0;
}
