#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
struct SegmentTree
{
	struct Node
	{
		ll lazy, sum;
		
		Node(ll val = 0ll) : sum(val), lazy(0) {}
		
		Node operator + (Node &other)
		{
			Node res;
			res.sum = sum + other.sum;
			return res;
		}
	};	
	
	vector<Node> st;
	int n;
	
	SegmentTree(int n) : n(n) { st.resize(4 * n + 10); }
	
	void pass(int head, int l, int r)
	{
		if (st[head].lazy == 0) return;
		
		ll &v = st[head].lazy;
		st[head].sum += (r - l + 1) * v;
		
		if (l != r)
		{
			st[2 * head].lazy += v;
			st[2 * head + 1].lazy += v;
		}
		
		v = 0;
	}
	
	void update(int head, int l, int r, int u, int v, ll val)
	{
		pass(head, l, r);
		if (l > v || r < u) return;
		if (u <= l && r <= v)
		{
			st[head].lazy += val;
			pass(head, l, r);
			return;
		}
		
		int mid = l + r >> 1;
		update(2 * head, l, mid, u, v, val);
		update(2 * head + 1, mid + 1, r, u, v, val);
		
		st[head] = st[2 * head] + st[2 * head + 1];
	}
	
	void update(int u, int v, ll val) { update(1, 1, n, u, v, val); }
	
	ll query(int head, int l, int r, int u, int v)
	{
		pass(head, l, r);
		if (l > v || r < u) return 0ll;
		if (u <= l && r <= v) return st[head].sum;
		
		int mid = l + r >> 1;
		return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
	}
	
	ll query(int u, int v) { return query(1, 1, n, u, v); }
};
 
int n, c;
 
void input()
{
	cin >> n >> c;
	
	SegmentTree seg(n);
	
	while (c--)
	{
		int type; cin >> type;
		
		if (type == 0)
		{
			int u, v; cin >> u >> v;
			ll val; cin >> val;
			
			seg.update(u, v, val);
		} else
		{
			int u, v; cin >> u >> v;
			
			cout << seg.query(u, v) << '\n';
		}
	}
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
	while (t--)
		input();
 
	return 0;
}
 
