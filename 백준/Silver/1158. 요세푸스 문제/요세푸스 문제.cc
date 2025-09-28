#include <iostream>
#include <deque>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    if (!(std::cin >> N >> K)) return 0;

    std::deque<int> dq;
    for (int i = 1; i <= N; ++i) dq.push_back(i);

    std::vector<int> ans;
    ans.reserve(N);

    while (!dq.empty()) {
        for (int i = 0; i < K - 1; ++i) {
            int x = dq.front();
            dq.pop_front();
            dq.push_back(x);
        }
        ans.push_back(dq.front());
        dq.pop_front();
    }

    std::cout << "<";
    for (int i = 0; i < N; ++i) {
        std::cout << ans[i];
        if (i != N - 1) std::cout << ", ";
    }
    std::cout << ">";
    return 0;
}
