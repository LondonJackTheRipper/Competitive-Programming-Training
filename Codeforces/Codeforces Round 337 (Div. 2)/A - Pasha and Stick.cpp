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

	int t = 1;
	while (t--) solve();

    return 0;
}

// main program

void solve()
{
	int n; cin >> n;
	
	if (n % 2 == 1)
	{
		cout << 0 << '\n';
		return;
	}
	
	n /= 2;
	cout << n / 2 - (n % 2 == 0) << '\n';
}

