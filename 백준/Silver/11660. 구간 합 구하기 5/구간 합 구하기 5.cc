#include <iostream>
#include <vector>

using namespace std;

int arr[1025][1025] = { 0, };

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(N));

    // 입력받기
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            cin >> map[i][k];
        }
    }

    // 누적합 계산
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= N; k++)
        {
            arr[i][k] = map[i - 1][k - 1] 
                      + arr[i - 1][k]   // 위쪽 값
                      + arr[i][k - 1]   // 왼쪽 값
                      - arr[i - 1][k - 1]; // 겹친 부분 제거
        }
    }

    // 질의 처리
    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 좌표를 1-based에서 0-based로 변환
        int result = arr[x2][y2] 
                   - arr[x1 - 1][y2] 
                   - arr[x2][y1 - 1] 
                   + arr[x1 - 1][y1 - 1];

        cout << result << '\n';
    }

    return 0;
}
