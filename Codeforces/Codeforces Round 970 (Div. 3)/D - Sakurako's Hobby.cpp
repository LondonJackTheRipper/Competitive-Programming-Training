#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 2e5 + 9;

int p[maxn];
string s;
int n;

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	cin >> s; s = " " + s;
	
	vector<int> vis(n + 1, 0), ans(n + 1, 0);
	for (int i = 1; i <= n; i++)
		if (vis[i] == 0)
		{
			vector<int> process;
			int tmp = i;
			while (vis[tmp] == 0)
			{
				vis[tmp] = 1;
				process.push_back(tmp);
				tmp = p[tmp];
			}
			int cnt = 0;
			for (int val : process)
				cnt += (s[val] == '0');
			for (int val : process)
				ans[val] = cnt;
		} 
		
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
