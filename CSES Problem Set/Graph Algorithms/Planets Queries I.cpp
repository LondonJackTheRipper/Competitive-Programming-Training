#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 2e5 + 9;
 
int n, q;
int par[32][maxn];
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) cin >> par[0][i];
	
	for (int j = 1; j < 31; j++)
		for (int i = 1; i <= n; i++)
			par[j][i] = par[j - 1][par[j - 1][i]];
			
	while (q--)
	{
		int x, k; cin >> x >> k;
		
		for (int i = 0; i < 31; i++)
			if (k >> i & 1)
				x = par[i][x];
				
		cout << x << '\n';
	}
 
	return 0;
}
