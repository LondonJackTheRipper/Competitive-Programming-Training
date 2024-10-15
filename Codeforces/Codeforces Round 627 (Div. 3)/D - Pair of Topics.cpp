#include<bits/stdc++.h>

using namespace std;

#define ll long long

const string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".INP").c_str(), "r"))
    {
        freopen((name + ".INP").c_str(), "r", stdin);
        freopen((name + ".OUT").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) solve();

    return 0;
}

// main program
const int maxn = 2e5 + 9;

int n;
int a[maxn];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) 
	{
		int x; cin >> x;
		a[i] -= x;
	}
	
	sort(a + 1, a + n + 1);
	
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= 0) continue;
		int pos = upper_bound(a + 1, a + n + 1, -a[i]) - a;
		res += i - pos;
	}
	cout << res << '\n';
}
