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
	int n; cin >> n;
	int a[n + 1];
	for (int i = 0; i < n; i++) cin >> a[i];
	
	bool check = false;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
			if (mask >> i & 1)	
				sum += a[i];
			else
				sum -= a[i];
		if (sum % 360 == 0) check = true;	
	}	
	
	cout << (check == true ? "YES\n" : "NO\n");
}
