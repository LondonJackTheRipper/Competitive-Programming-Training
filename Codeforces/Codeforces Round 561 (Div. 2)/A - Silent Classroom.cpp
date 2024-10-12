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
int C(int n) { return n * (n - 1) / 2; }

void solve()
{
	int n; cin >> n;
	vector<int> cnt(30, 0);
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		cnt[str[0] - 'a']++;
	}
	
	int res = 0;
	for (int i = 0; i < 26; i++)
		res += C(cnt[i] / 2) + C(cnt[i] - cnt[i] / 2);
	cout << res << '\n';
}
