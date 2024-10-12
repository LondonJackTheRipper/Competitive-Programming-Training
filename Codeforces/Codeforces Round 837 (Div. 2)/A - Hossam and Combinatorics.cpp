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

void solve()
{
	int n; cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	unordered_map<int, int> mp;
	int comp = a[n] - a[1];
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += mp[a[i] - comp] + (comp == 0 ? 0 : mp[a[i] + comp]);
		mp[a[i]]++;
	}
	
	cout << 2 * res << '\n';
}
