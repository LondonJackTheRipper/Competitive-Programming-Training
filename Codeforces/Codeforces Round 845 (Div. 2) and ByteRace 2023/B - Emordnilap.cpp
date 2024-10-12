#include<bits/stdc++.h>

using namespace std;

#define ll long long

string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".INP").c_str(), "r"))
    {
        freopen((name + ".INP").c_str(), "r", stdin);
        freopen((name + ".OUT").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

    return 0;
}

// main program
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

int C(int n)
{
	if (n < 2) return 0;
	int res = mul(n, n - 1);
	return mul(res, power(2, mod - 2));
}

void solve()
{
	int n; cin >> n;
	int fac = n;
	for (int i = 1; i < n; i++)
	{
		fac = mul(fac, i);
	}
	cout << mul(fac, mul(2, C(n))) << '\n';
}
