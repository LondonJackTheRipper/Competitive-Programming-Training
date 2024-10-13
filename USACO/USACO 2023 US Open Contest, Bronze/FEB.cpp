#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

int n; 

void input()
{
	cin >> n;
	vector<char> v(n);
	vector<int> pos;
	
	for (int i = 0; i < n; i++)
		cin >> v[i];	
	if (count(v.begin(), v.end(), 'F') == n)
		v[0] = 'E';
	for (int i = 0; i < n; i++)
		if (v[i] != 'F')
			pos.pb(i);
		
	int ones = n - 1 + pos[0] - pos.back();
	int mn = 0, mx = 0;
	for (int i = 0; i < pos.size() - 1; i++)
	{
		int a = pos[i];
		int b = pos[i + 1];
		mn += ((v[a] != v[b]) ^ ((b - a) & 1));
		mx += b - a - (v[a] != v[b]);
	}
	
	int l = mn;
	int r = mx + ones;
	int step = 1 + (ones == 0);
	vector<int> ans;
	
	for (int i = l; i <= r; i += step)
		ans.pb(i);
		
	cout << ans.size() << '\n';
	for (int x : ans) cout << x << '\n';
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}

