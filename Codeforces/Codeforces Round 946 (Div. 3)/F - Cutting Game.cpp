#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 1e9 + 9;
int a, b, n, m;

void input()
{
	cin >> a >> b >> n >> m;
	
	set<pair<int, int>> remove;
	vector<pair<int, int>> ver, hor;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		ver.pb({x, y});
		hor.pb({y, x});
	}
	sort(ver.begin(), ver.end());
	sort(hor.begin(), hor.end());
	int u = 1, d = a;
	int l = 1, r = b;
	int vu = 0, vd = n - 1;
	int vl = 0, vr = n - 1;
	vector<int> ans(2, 0);
	for (int i = 0; i < m; i++)
	{
		char x; cin >> x;
		int k; cin >> k;
		
		if (x == 'U')
		{
			u += k;
			while (vu <= vd && ver[vu].first < u)
			{
				if (remove.find(ver[vu]) == remove.end())
				{
					ans[i % 2]++;
					remove.insert(ver[vu]);
				}
				vu++;
			}
		}
		if (x == 'D')
		{
			d -= k;
			while (vu <= vd && ver[vd].first > d)
			{
				if (remove.find(ver[vd]) == remove.end())
				{
					ans[i % 2]++;
					remove.insert(ver[vd]);
				}
				vd--;
			}
		}
		if (x == 'L')
		{
			l += k;
			while (vl <= vr && hor[vl].first < l)
			{
				pair<int, int> tmp = {hor[vl].second, hor[vl].first};
				if (remove.find(tmp) == remove.end())
				{
					ans[i % 2]++;
					remove.insert(tmp);
				}
				vl++;
			}
		}
		if (x == 'R')
		{
			r -= k;
			while (vl <= vr && hor[vr].first > r)
			{
				pair<int, int> tmp = {hor[vr].second, hor[vr].first};
				if (remove.find(tmp) == remove.end())
				{
					ans[i % 2]++;
					remove.insert(tmp);
				}
				vr--;
			}
		}
	}
	
	cout << ans[0] << ' ' << ans[1] << '\n';
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
