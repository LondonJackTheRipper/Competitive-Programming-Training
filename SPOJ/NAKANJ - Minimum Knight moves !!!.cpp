#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
int dx[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
int dy[8] = {-1, 1, -2, 2, -1, 1, -2, 2};
 
bool isin(int x, int y) { return 1 <= x && x <= 8 && 1 <= y && y <= 8; }
 
int dist[10][10];
void BFS(int u, int v)
{
	dist[u][v] = 0;
	queue<pair<int, int>> q;
	q.push({u, v});
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 8; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if (!isin(xx, yy) || dist[xx][yy] != -1) continue;
			
			dist[xx][yy] = dist[x][y] + 1;
			q.push({xx, yy});
		}
	}
}
 
void input()
{
	string s1; cin >> s1; 
	string s2; cin >> s2;
	int x1 = s1[1] - '0', y1 = (s1[0] - 'a') + 1; 
	int x2 = s2[1] - '0', y2 = (s2[0] - 'a') + 1;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			dist[i][j] = -1;
			
	BFS(x1, y1);
	
	cout << dist[x2][y2] << '\n';
}
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
	
	int t; cin >> t;
	while (t--) input();
 
	return 0;
}
