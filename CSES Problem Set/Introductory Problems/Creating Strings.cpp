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
 
	int t = 1;
//	cin >> t;
	while (t--) solve();
 
	return 0;
}
 
string s;
set<string> res;
 
string cur = "";
void generate(int pos, vector<int>& mark)
{
	if (pos == s.length())
	{
		res.insert(cur);
		return;
	}
	
	for (int i = 0; i < s.length(); i++)
	{
		if (mark[i] == 1) continue;
		
		cur.push_back(s[i]);
		mark[i] = 1;
		generate(pos + 1, mark);
		cur.pop_back();
		mark[i] = 0;
	}
}
 
void solve()
{
	cin >> s;
 
	vector<int> mark(s.length(), 0);	
	generate(0, mark);
	
	cout << res.size() << '\n';
	for (string str : res)
		cout << str << '\n';
}
