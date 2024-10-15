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

void solve()
{
	int power[11];
	power[0] = 1;
	for (int i = 1; i <= 10; i++) power[i] = power[i - 1] * 3;
	
	int m; cin >> m;
	vector<int> a;
	
	for (int i = 10; i >= 0; i--)
	{
		while (m >= power[i])
		{
			a.push_back(i);
			m -= power[i];
		}
	}
	
	cout << a.size() << '\n';	
	for (int x : a) cout << x << ' ';
}
