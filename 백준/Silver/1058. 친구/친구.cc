#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> adj(N);
    for (int i = 0; i < N; i++) cin >> adj[i];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        set<int> friends;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (adj[i][j] == 'Y') {
                friends.insert(j); // 직접 친구
            } else {
                // 친구의 친구 체크
                for (int k = 0; k < N; k++) {
                    if (adj[i][k] == 'Y' && adj[k][j] == 'Y') {
                        friends.insert(j);
                        break;
                    }
                }
            }
        }
        ans = max(ans, (int)friends.size());
    }

    cout << ans << "\n";
    return 0;
}
