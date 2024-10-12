#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  Handle codeforces : quangminh98
  
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int mod = 1e9 + 7;
 
int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
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
 
vector<int> fac, inv;
void init(int n)
{
	fac.resize(n + 2, 1);
	inv.resize(n + 2, 1);
	for (int i = 1; i <= n; i++)
		fac[i] = mul(fac[i - 1], i);
	inv[n] = power(fac[n], mod - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = mul(inv[i + 1], i + 1);
}
 
int C(int k, int n) { return mul(fac[n], mul(inv[k], inv[n - k])); }
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	init(1e6);
	
	int n; cin >> n;
	while (n--)
	{
		int a, b; cin >> a >> b;
		
		cout << C(b, a) << '\n';
	}
 
	return 0;
}
