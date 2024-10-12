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
 
const ll inf = 1e18 + 1;
const int maxn = 509;
ll a[maxn][maxn];
int n, m, q;
 
void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}
 
void input()
{
	cin >> n >> m >> q;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (i != j)
			a[i][j] = inf; else a[i][j] = 0;
	for (int i = 0; i < m; i++)
	{
		ll x, y, w; cin >> x >> y >> w;
		a[x][y] = min(a[x][y], w);
		a[y][x] = min(a[y][x], w);
	}
	floyd();
	
	while (q--)
	{
		int x, y; cin >> x >> y;
		cout << (a[x][y] == inf ? -1 : a[x][y]) << '\n';
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
