#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int cnt = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int dz[2] = { -1, 1 };

struct Pos
{
public:
    int x;
    int y;
    int z;

    Pos(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int m, n, h;
    int notTomatoes = 0;
    queue<Pos> q;
    cin >> m >> n >> h;
    
    vector<vector<vector<int>>> map(h, vector<vector<int>>(n, vector<int>(m)));

    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < m; k++)
            {
                int val;
                cin >> val;

                map[j][i][k] = val;
                if (val == 1)
                {
                    q.push(Pos(k, i, j));
                }
                else if (val == 0)
                {
                    notTomatoes++;
                }
            }
        }
    }

    if (notTomatoes == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
  
    while (!q.empty())
    {
        int size = q.size();
        cnt++;

        for (int s = 0; s < size; s++)
        {
            Pos pos = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int xx = pos.x + dx[i];
                int yy = pos.y + dy[i];

                if (xx < 0 || xx >= m || yy < 0 || yy >= n)
                {
                    continue;
                }

                if (map[pos.z][yy][xx] == 0)
                {
                    map[pos.z][yy][xx] = 1;
                    notTomatoes--;
                    q.push(Pos(xx, yy, pos.z));
                }
            }

            for (int i = 0; i < 2; i++)
            {
                int zz = pos.z + dz[i];

                if (zz < 0 || zz >= h)
                {
                    continue;
                }

                if (map[zz][pos.y][pos.x] == 0)
                {
                    map[zz][pos.y][pos.x] = 1;
                    notTomatoes--;
                    q.push(Pos(pos.x, pos.y, zz));
                }
            }
        }
    }
    
    if (notTomatoes == 0)
        cout << cnt - 1<< '\n';
    else
        cout << -1 << '\n';

    return 0;
}