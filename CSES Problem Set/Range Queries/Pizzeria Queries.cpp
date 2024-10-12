#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const ll oo = LLONG_MAX;
const int maxn = 2e5 + 9;
const int segsize = 4 * maxn;
 
int n, q;
int p[maxn];
 
class SegmentTree
{
private: 
	vector<ll> st;
	bool isreverse;
	int n;
	
	void build(int head, int l, int r, int *arr)
	{
		if (l == r)
		{
			st[head] = (isreverse == true ? n + 1 - l : l) + arr[l];
			return;
		}
		
		int mid = l + r >> 1;
		build(2 * head, l, mid, arr);
		build(2 * head + 1, mid + 1, r, arr);
		
		st[head] = min(st[2 * head], st[2 * head + 1]);
	}
	
	void update(int head, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			st[head] = (isreverse == true ? n + 1 - l : l) + val;
			return;
		}
		
		int mid = l + r >> 1;
		if (pos <= mid)
			update(2 * head, l, mid, pos, val);
		else
			update(2 * head + 1, mid + 1, r, pos, val);
			
		st[head] = min(st[2 * head], st[2 * head + 1]);
	}
	
	ll query(int head, int l, int r, int u, int v)
	{
		if (l > v || r < u) return LLONG_MAX;
		if (u <= l && r <= v) return st[head];
		
		int mid = l + r >> 1;
		return min(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
	}
public:
	SegmentTree(int n, int *arr, bool isreverse) : n(n), isreverse(isreverse)
	{
		st.resize(segsize, oo);
		build(1, 1, n, arr);
	}
	
	void update(int pos, int val) { update(1, 1, n, pos, val); }
	ll query(int u, int v) { return query(1, 1, n, u, v); }
};
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> p[i];
	
	SegmentTree left(n, p, 1), right(n, p, 0);
	
	while (q--)
	{
		int type; cin >> type;
		
		if (type == 1)
		{
			int k, x; cin >> k >> x;
			
			left.update(k, x);
			right.update(k, x);
			p[k] = x;
		} else
		{
			int k; cin >> k;
			
			int l = left.query(1, k) - (n + 1 - k);
			int r = right.query(k, n) - k;
			
			cout << min(l, r) << '\n';
		}
	}
 
	return 0;
}
