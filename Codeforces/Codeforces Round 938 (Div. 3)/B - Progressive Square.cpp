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

	int t;
	cin >> t;
	while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n, c, d; cin >> n >> c >> d;
    map<int, int> mp;
    int mn = 1e9 + 9;
    for (int i = 0; i < n * n; i++)
    {
    	int x; cin >> x;
    	mn = min(mn, x);
    	mp[x]++;
	}
	int a[n + 1];
	for (int i = 0; i < n; i++)
	{
		a[i] = mn;
		if (mp[mn] == 0) { cout << "NO\n"; return; }
		mp[mn]--;
		mn += d;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int val = a[j] + c;
			if (mp[val] == 0) { cout << "NO\n"; return; }
			mp[val]--;
			a[j] = val;
		}
	}
	cout << "YES\n";
}
