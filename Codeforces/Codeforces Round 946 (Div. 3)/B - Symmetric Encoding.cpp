#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

map<char, char> solve(string s)
{
	int i = 0, j = s.length() - 1;
	map<char, char> res;
	
	while (i <= j)
	{
		res[s[i]] = s[j];
		res[s[j]] = s[i];
		i++; j--;
	}
	
	return res;
}


void input()
{
	int n; cin >> n;
	string s; cin >> s;
	set<int> se;
	map<char, char> mp;
	
	for (char x : s) se.insert(x);
	string tmp = "";
	for (auto it = se.begin(); it != se.end(); it++) tmp.push_back(*it);
	mp = solve(tmp);
	
	for (char x : s)
		cout << mp[x];
	cout << '\n';
}

int main()
{
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
