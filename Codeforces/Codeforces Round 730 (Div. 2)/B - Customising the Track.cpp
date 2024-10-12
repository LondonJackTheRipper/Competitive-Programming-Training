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
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		sum += x;
	}
	
	if (sum % n == 0)
	{
		cout << 0 << '\n';
		return;
	}
	int cnt1 = n - (sum % n), cnt2 = sum % n;
	cout << 1ll * cnt1 * cnt2 << '\n';
}
