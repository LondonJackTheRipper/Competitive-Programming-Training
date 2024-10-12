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

ll compute(int k, int num)
{
	ll res = 0;
	for (int i = 1; i <= num; i++)	
		res += max(0, num - (i + k - 1) + 1);
	return res;
}

void solve()
{
	int n, k, q; cin >> n >> k >> q;
	vector<int> v;
	int cur = 0;
	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (x <= q)
			cur++;
		else
		{
			res += compute(k, cur);
			cur = 0;
		}
	}
	res += compute(k, cur);
	
	cout << res << '\n';
	
	
}
