#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "test";

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
	string s; cin >> s;
	
	vector<int> proc;
	int cur = 0;
	for (char c : s)
	{
		if (c == '0')
		{
			if (cur != 0)
				proc.push_back(cur);
			cur = 0;
		} else
			cur++;
	}
	if (cur != 0)
		proc.push_back(cur);
		
	sort(proc.begin(), proc.end(), greater<int>());
	int res = 0;
	for (int i = 0; i < proc.size(); i += 2)
		res += proc[i];
	cout << res << '\n';
}
