#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "cowsignal";

void solve();
signed main()
{
	if (fopen((name + ".in").c_str(), "r"))
	{
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
//	cin >> t;
	while (t--) solve();

	return 0;
}

const int maxn = 19;

char arr[maxn][maxn];
int n, m, k;

void solve()
{
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
			
	for (int i = 1; i <= k * m; i++)
		for (int j = 1; j <= k * n; j++)
		{
			cout << arr[(i + k - 1) / k][(j + k - 1) / k];
			if (j == k * n) cout << '\n';
		}
}

