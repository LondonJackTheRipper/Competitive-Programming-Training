#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 109;
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
int arr[maxn][maxn];
int vis[maxn][maxn];
int n, m;
 
inline bool isin(int x, int y) { return 1 <= min(x, y) && x <= n && y <= m; }
 
void input()
{
	cin >> n >> m;
	
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			vis[i][j] = 0;
			if (i == 1 || j == 1 || i == n || j == m)
				pq.push(make_tuple(arr[i][j], i, j));
		}
		
	int ans = 0;
	while (!pq.empty())
	{
		int d = get<0>(pq.top());
		int u = get<1>(pq.top());
		int v = get<2>(pq.top());
		pq.pop();
		
		if (vis[u][v] == 1) continue;
		vis[u][v] = 1;
		
		ans += d - arr[u][v];
		
		for (int i = 0; i < 4; i++)
		{
			int uu = u + dx[i];
			int vv = v + dy[i];
			
			if (!isin(uu, vv) || vis[uu][vv] == 1) continue;
			
			pq.push(make_tuple(max(d, arr[uu][vv]), uu, vv));
		}
	}
	
	cout << ans << '\n';
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
