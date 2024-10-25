#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int map[101][101] = { 0, };
bool visit[101][101] = { false, };
int cnt = 0;
int dx[4] = { -1, 1, 0, 0 };  // 세로 변화 (행 이동)
int dy[4] = { 0, 0, -1, 1 };  // 가로 변화 (열 이동)
int N, M, K;

int DFS(int r, int c)
{
    int val = 1;

    for (int i = 0; i < 4; i++)
    {
        int rr = r + dx[i];
        int cc = c + dy[i];

        if (rr < 0 || rr >= N || cc < 0 || cc >= M)
            continue;

        if (!visit[rr][cc] && map[rr][cc] == 1)
        {
            visit[rr][cc] = true;
            val += DFS(rr, cc);
        }
    }

    return val;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;

        map[r - 1][c - 1] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < M; k++)
        {
            int val = 0;

            if (!visit[i][k] && map[i][k] == 1)
            {
                visit[i][k] = true;
                val = DFS(i, k);
            }

            if (val > cnt)
                cnt = val;
        }
    }

    cout << cnt << '\n';

    return 0;
}
