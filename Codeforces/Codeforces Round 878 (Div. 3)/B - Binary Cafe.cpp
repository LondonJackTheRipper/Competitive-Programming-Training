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
	int n, k; cin >> n >> k;
	
	int highest;
	for (int i = 0; i < 30; i++)
		if (n >> i & 1)
			highest = i;
			
	if (highest < k)
		cout << n + 1 << '\n';
	else
		cout << (1 << k) << '\n';
}
