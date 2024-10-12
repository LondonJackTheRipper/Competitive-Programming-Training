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
 
char a[1001][1001];
int d[1001][1001];
int pre[1001][1001];
int n, m, xa, xb, ya, yb;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
string dir = "ULRD";
 
void BFS(int x, int y)
{
	d[x][y] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	 
	while (!q.empty())
	{
	 	int u = q.front().first;
	 	int v = q.front().second;
	 	q.pop();
	 	
	 	for (int i = 0; i < 4; i++) 
	 	{
	 		int uu = u + dx[i], vv = v + dy[i];
	 		if (uu < 0 || vv < 0 || uu >= n || vv >= m || d[uu][vv] == 1 || a[uu][vv] == '#')
	 			continue;
	 		
	 		d[uu][vv] = 1;
	 		pre[uu][vv] = i;
	 		q.push(make_pair(uu, vv));
	 	}
	}
}
 
void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] == 'A') xa = i, ya = j;
			if (a[i][j] == 'B') xb = i, yb = j;
		}
	BFS(xa, ya);
	
	if (!d[xb][yb]) cout << "NO\n"; else 
	{
		cout << "YES\n";
		vector<char> res;
		int cnt = 0;
		while (xb != xa || yb != ya)
		{
			int tmp = pre[xb][yb];
			cnt++;
			res.pb(dir[tmp]);
			xb = xb - dx[tmp];
			yb = yb - dy[tmp];
		}
		cout << cnt << '\n';
		for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	
    return 0;
}
