#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int n;
string s;

void input()
{
	cin >> n >> s;
	
	if (n % 2 == 0)
	{
		vector<int> even(30, 0), odd(30, 0);
		int mx_even = 0, mx_odd = 0;
		for (int i = 0; i < s.length(); i++)
			if (i % 2 == 0)
			{
				odd[s[i] - 'a']++;
				mx_odd = max(mx_odd, odd[s[i] - 'a']);
			} else
			{
				even[s[i] - 'a']++;
				mx_even = max(mx_even, even[s[i] - 'a']);
			}
		cout <<  n - mx_even - mx_odd;
	} else
	{
		vector<vector<int>> pre(2, vector<int>(30, 0)), suff(2, vector<int>(30, 0));
		for (int i = 0; i < n; i++)
			suff[i % 2][s[i] - 'a']++;
		
		int res = 1e9;
		for (int i = 0; i < n; i++)
		{
			suff[i % 2][s[i] - 'a']--;
			
			int ans = n;
			for (int parity = 0; parity < 2; parity++)
			{
				int mx = 0;
				for (int c = 0; c < 26; c++)
					mx = max(mx, pre[parity][c] + suff[parity ^ 1][c]);
				ans -= mx;
			}
			
			res = min(res, ans);
			pre[i % 2][s[i] - 'a']++;
		}
		cout << res;
	}
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
