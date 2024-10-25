#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 1e5 + 9;

int arr[maxn];
int n;

int solve(int u, int v)
{
	int l = u, r = v;
	int ans = v - u + 1;
	u--, v++;
	
	while (0 < u && arr[u] != (u + 1 == l ? arr[u + 1] ^ 1 : arr[u + 1])) u--, ans++;
	while (v <= n && arr[v] != (v - 1 == r ? arr[v - 1] ^ 1 : arr[v - 1])) v++, ans++;
	
	return ans;
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	arr[0] = arr[1] ^ 1;
	arr[n + 1] = arr[n] ^ 1;

	vector<pair<int, int>> process;
	int prev_idx = 1, cur_idx = 1; 
	for (int i = 2; i <= n; i++)
		if (arr[i] != arr[i - 1])
			cur_idx++;
		else
		{
			process.push_back(make_pair(prev_idx, cur_idx));
			prev_idx = i = cur_idx = i;
		}
	process.push_back(make_pair(prev_idx, cur_idx));
	
	int res = 0;
	for (pair<int, int> p : process)
		res = max(res, solve(p.first, p.second));
	
	cout << res << '\n';
	
	return 0;
}
