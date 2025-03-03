#include<bits/stdc++.h>

using namespace std;

#define ll long long

string name = "test";

void solve();
void prepare();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prepare();
	int t;
	cin >> t;
	while (t--) solve();

    return 0;
}

// main program
map<string, int> mp;
vector<string> str;
void prepare()
{
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
		{
			if (i == j) continue;
			string tmp = "";
			tmp.push_back(char('a' + i));
			tmp.push_back(char('a' + j));
			str.push_back(tmp);
		}
	sort(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++)
		mp[str[i]] = i + 1;	
}

void solve()
{
	string s; cin >> s;
	cout << mp[s] << '\n';
}

