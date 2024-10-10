#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

string s;
int n;

map<char, char> mp = {
	{'N', 'S'},
	{'S', 'N'},
	{'E', 'W'},
	{'W', 'E'}
};

void input()
{
	cin >> n >> s;
	
	int x = 0, y = 0;
	for (char i : s)
	{
		if (i == 'N') y++;
		if (i == 'S') y--;
		if (i == 'E') x++;
		if (i == 'W') x--;
	}
	
	if (x % 2 || y % 2)
	{
		cout << "NO\n";
		return;
	}
	
	vector<char> ans(n, 'R');
	if (x == 0 && y == 0)
	{
		if (n == 2)
		{
			cout << "NO\n";
			return;
		}
		ans[0] = ans[s.find(mp[s[0]])] = 'H';
	} else 
	{
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'N' && y > 0)
			{
				y -= 2;
				ans[i] = 'H';
			}
			if (s[i] == 'S' && y < 0)
			{
				y += 2;
				ans[i] = 'H';
			}
			if (s[i] == 'E' && x > 0)
			{
				x -= 2;
				ans[i] = 'H';
			}
			if (s[i] == 'W' && x < 0)
			{
				x += 2;
				ans[i] = 'H';
			}
		}
	}
	
	for (int i = 0; i < n; i++) 
		cout << ans[i];
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
