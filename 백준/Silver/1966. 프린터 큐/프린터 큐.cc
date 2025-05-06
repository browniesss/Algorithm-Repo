#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        queue<pair<int, int>> q;
        priority_queue<int> pq;

        // 문서의 (원래 인덱스, 중요도) 를 큐에 넣고
        // 우선순위 큐에는 중요도만 넣어서 최대값을 빠르게 꺼낼 수 있게 한다
        for (int i = 0; i < N; ++i) {
            int imp;
            cin >> imp;
            q.emplace(i, imp);
            pq.push(imp);
        }

        int printed = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            // 현재 앞 문서 중요도가 남은 문서들 중 최대값보다 작으면
            if (cur.second < pq.top()) {
                // 뒤로 재배치
                q.push(cur);
            }
            else {
                // 인쇄
                ++printed;
                pq.pop();
                // 만약 이 문서가 우리가 찾던 문서라면 순서를 출력하고 다음 케이스로
                if (cur.first == M) {
                    cout << printed << "\n";
                    break;
                }
            }
        }
    }

	return 0;
}