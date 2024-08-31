#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector<vector<char>> map(20, vector<char>(20));
bool visitword[26];
int maximum = -1;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0 , 1, 0 };
int R, C;

void DFS(int x, int y, int val)
{
	if (maximum <= val)
	{
		maximum = val;
	}

	for (int i = 0; i < 4; i++)
	{
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		
		if (xx >= 0 && xx < C && yy >= 0 && yy < R)
		{
			char aa = map[yy][xx];
			if (!visitword[aa - 'A'])
			{
				visitword[aa - 'A'] = true;
				DFS(xx, yy, val + 1);
				visitword[aa - 'A'] = false;
			}
		}
	}
}

int main()
{
	string word;
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		cin >> word;
		for (int k = 0; k < C; k++)
		{
			map[i][k] = word[k];
		}
	}

	visitword[map[0][0] - 'A'] = true;
	DFS(0, 0, 1);

	cout << maximum << endl;

	return 0;
}