#include <iostream>
#include <algorithm>

using namespace std;

bool isArrived = false;
int n;
int map[3][3] = {0,};
int visited[3][3] = {0,};
int dx[4] = { 0, 1, 0 , -1};
int dy[4] = {-1, 0, 1, 0};

void DFS(int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        isArrived = true;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int xx = x + (map[y][x] * dx[i]);
        int yy = y + (map[y][x] * dy[i]);

        if (xx < 0 || xx >= n || yy < 0 || yy >= n)
        {
            continue;
        }

        if (!visited[yy][xx])
        {
            visited[yy][xx] = true;
            DFS(xx, yy);
            visited[yy][xx] = false;
        }
    }
}

int main() {

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < n; k++)
        {
            int val;
            cin >> val;

            map[i][k] = val;
        }
    }    

    visited[0][0] = true;
    DFS(0, 0);

    if (isArrived)
    {
        cout << "HaruHaru" << "\n";
    }
    else
    {
        cout << "Hing" << "\n";
    }
    
    return 0;
}