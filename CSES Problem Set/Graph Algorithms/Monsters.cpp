#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pll pair<long long, long long>
#define vll vector<long long>
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define vc vector<char>
#define vi vector<int>
#define ll long long
#define pb push_back
 
const int maxn = 1009;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
string dir = "ULRD";
int par[maxn][maxn];
int arr[maxn][maxn];
queue<vector<int>> q;
int n, m;
 
bool check(int i, int j)
{
	return (i == 1 || i == n || j == 1 || j == m);
}
 
pair<int, int> bfs()
{
	while (!q.empty())
	{
		vector<int> nxt = q.front();
		q.pop();
		
		if (nxt[0] == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				int x = nxt[1] + dx[i];
				int y = nxt[2] + dy[i];
				if (0 < x && x <= n && 0 < y && y <= m && arr[x][y])
				{
					arr[x][y] = 0;
					q.push({0, x, y});
				}
			}
		} else 
		{
			int x = nxt[1];
			int y = nxt[2];
			
			if (check(x, y))
				return make_pair(x, y);
			for (int i = 0; i < 4; i++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (0 < xx && xx <= n && 0 < yy && yy <= m && arr[xx][yy])
				{
					arr[xx][yy] = 0;
					par[xx][yy] = i;
					q.push({1, xx, yy});
				}
			}
		}
	}
	
	return make_pair(0, 0);
}
 
void input()
{
	cin >> n >> m;
	
	int x, y;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char c; cin >> c;
			if (c == 'M')
				q.push({0, i, j});
			else if (c == 'A')
				x = i, y = j;
			else if (c == '.')
				arr[i][j] = 1;
		}
	q.push({1, x, y});
	pair<int, int> res = bfs();
	
	if (res.first == 0 && res.second == 0)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		string ans;
		int u = res.first, v = res.second;
		
		while (u != x || v != y)
		{
			ans += dir[par[u][v]];
			int tmp = u;
			u -= dx[par[u][v]];
			v -= dy[par[tmp][v]];
		}
		reverse(ans.begin(), ans.end());
		
		cout << ans.size() << '\n';
		for (char x : ans) cout << x;
		cout << '\n';
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
	
	return 0;
}
