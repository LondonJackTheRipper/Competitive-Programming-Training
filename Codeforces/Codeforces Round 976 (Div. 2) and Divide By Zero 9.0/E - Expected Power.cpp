#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "test";

void solve();
signed main()
{
	if (fopen((name + ".inp").c_str(), "r"))
	{
		freopen((name + ".inp").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

// main program
const int maxn = 2e5 + 9;
const int mod = 1e9 + 7;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }

int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

const int INV = power(1e4, mod - 2);

int n;
int dp[2][1024];
int a[maxn], p[maxn];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) 
	{
		cin >> p[i];
		p[i] = mul(p[i], INV);
	}
	
	for (int i = 0; i < 2; i++) for (int j = 0; j < 1024; j++) dp[i][j] = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			dp[1][j] = mul(dp[0][j ^ a[i]], p[i]);
			dp[1][j] = add(dp[1][j], mul(dp[0][j], sub(1, p[i])));
		}
		for (int j = 0; j < 1024; j++)
			dp[0][j] = dp[1][j];
	}
	
	int ans = 0;
	for (int i = 0; i < 1024; i++)
		ans = add(ans, mul(dp[0][i], power(i, 2)));
	cout << ans << '\n';
}
