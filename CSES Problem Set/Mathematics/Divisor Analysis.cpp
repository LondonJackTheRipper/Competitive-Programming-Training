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
const int phi = 1e9 + 6;
 
int add(int a, int b, int mod = mod) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b, int mod = mod) { a -= b; if (a < 0) a += mod; return a; }
int mul(int a, int b, int mod = mod) { return 1ll * a * b % mod; }
 
int power(int a, ll b)
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
 
int n;
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n;
	
	int number = 1, count = 1, up = 1, down = 1, count_2 = 1, proc = 1;
	while (n--)
	{
		int x, k; cin >> x >> k;
		number = mul(number, power(x, k));
		count = mul(count, k + 1);
		up = mul(up, sub(power(x, k + 1), 1));
		down = mul(down, sub(x, 1));
		proc = mul(power(proc, k + 1), power(power(x, (1ll * k * (k + 1)) / 2), count_2));
		count_2 = mul(count_2, k + 1, phi);
	}
	cout << count << ' ' << mul(up, power(down, mod - 2)) << ' ' <<  proc << '\n';
 
	return 0;
}
