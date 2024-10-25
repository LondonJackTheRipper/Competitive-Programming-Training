#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
vector<int> solve(int l, int u, vector<pair<ll, int>>& p, vector<ll>& pre, int k)
{
	for (int i = k - 1; i < pre.size(); i++)
	{
		ll sum = pre[i] - (i -  k < 0 ? 0 : pre[i - k]);
		if (l <= sum && sum <= u)
		{
			vector<int> ans;
			for (int j = i - k + 1; j <= i; j++)
				ans.push_back(p[j].second);
			return ans;
		}
	}
	return {};
}
 
vector<int> find_subset(int l, int u, vector<int> w)
{
	int n = w.size();
	vector<pair<ll, int>> p;
	for (int i = 0; i < n; i++)
		p.push_back(make_pair(w[i], i));
	sort(p.begin(), p.end());
	vector<ll> pre(n);
	for (int i = 0; i < n; i++)
		pre[i] = (i == 0 ? 0 : pre[i - 1]) + p[i].first;
	
	for (int i = 1; i <= n; i++)
	{
		if (pre[i - 1] > u || pre[n - 1] - (n - i - 1 < 0 ? 0 : pre[n - i - 1]) < l) 
			continue;
			
		vector<int> ans = solve(l, u, p, pre, i);
		if (!ans.empty())
			return ans;
	}
	
	return {};
}
