#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 1e5 + 9;

int n, m;
int p[maxn], diff[maxn];
ll a[maxn], b[maxn], c[maxn];

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> p[i];
	for (int i = 1; i < n; i++) cin >> a[i] >> b[i] >> c[i];
	a[n] = a[n - 1]; b[n] = b[n - 1]; c[n] = c[n - 1];
	
	for (int i = 1; i < m; i++)
	{
		int u = p[i];
		int v = p[i + 1];
		
		if (u > v)
		{
			u--;
			diff[v]++;
			diff[u + 1]--;
		} else
		{
			v--;
			diff[u]++;
			diff[v + 1]--;
		}
	}
	
	ll res = 0;
	int pre = 0;
	for (int i = 1; i <= n; i++)
	{
		pre += diff[i];
		
		int cost = (pre == 0 ? 0 : c[i]);
		res += min(pre * a[i], pre * b[i] + cost);
	}
	
	cout << res << '\n';

	return 0;
}
