#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
struct FenwickTree
{
	int n;
	vector<int> bits;
	
	FenwickTree(int n) : n(n) { bits.resize(n + 5, 0); }
	
	void update(int pos, int val)
	{
		for (; pos <= n; pos += (pos & (-pos)))
			bits[pos] += val;
	}
	
	int query(int pos)
	{
		int ans = 0;
		for (; pos > 0; pos -= (pos & (-pos)))
			ans += bits[pos];
		return ans;
	}
	
	int query(int u, int v) { return (query(v) - query(u - 1)); }
};
 
ll count_swaps(vector<int> s)
{
	int n = s.size();
	unordered_map<int, vector<int>> pos, neg;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] < 0)	
			neg[s[i]].push_back(i);
		else
			pos[s[i]].push_back(i);
	}
	
	FenwickTree bit(n);
	for (int i = 0; i < n; i++)
		bit.update(i + 1, 1);
	
	ll res = 0;
	vector<int> mark(n + 5, 1);
	for (int i = 0; i < n; i++)
	{
		if (mark[i] == 0) continue;
		mark[i] = 0;
		
		if (s[i] < 0)
		{
			neg[s[i]].pop_back();
			int j = pos[-s[i]].back(); 
			pos[-s[i]].pop_back();
			mark[j] = 0;
			res += bit.query(i + 2, j + 1) - 1;
			bit.update(i + 1, -1);
			bit.update(j + 1, -1);
		} else
		{
			pos[s[i]].pop_back();
			int j = neg[-s[i]].back();
			neg[-s[i]].pop_back();
			mark[j] = 0;
			res += bit.query(i + 1, j + 1) - 1;
			bit.update(i + 1, -1);
			bit.update(j + 1, -1);
		}
	}
	
	return res;
}
