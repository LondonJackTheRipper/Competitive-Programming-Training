#include<bits/stdc++.h>

using namespace std;

#define ll long long

string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	while (t--) solve();

    return 0;
}


void solve()
{
	int n, l, r, x; cin >> n >> l >> r >> x;
	int c[n + 1];
	for (int i = 0; i < n; i++) cin >> c[i];
	
	int res = 0;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		int mn = 1e9, mx = 0, sz = 0, sum = 0;
		for (int i = 0; i < n; i++)
			if (mask >> i & 1)
			{
				mn = min(mn, c[i]);
				mx = max(mx, c[i]);
				sum += c[i];
				sz++;	
			}
		if (sz > 1 && l <= sum && sum <= r && mx - mn >= x) res++;
	}
	cout << res << '\n';
}
