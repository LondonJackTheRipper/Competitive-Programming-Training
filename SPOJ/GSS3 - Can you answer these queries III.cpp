#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int oo = 1e9;
const int maxn = 50009;
 
int n, m;
int arr[maxn];
 
struct SegmentTree
{
	struct Node
	{
		int pre, suf, sum, finals;
		
		Node(int val = 0) : sum(val), pre(val), suf(val), finals(val) {}
		
		Node operator + (const Node &other)
		{
			if (sum == oo) return other;
			if (other.sum == oo) return *this;
			Node res;
			res.pre = max(pre, sum + other.pre);
			res.suf = max(other.suf, other.sum + suf);
			res.sum = sum + other.sum;
			res.finals = max({finals, other.finals, suf + other.pre});
			return res;
		}
	};
	
	vector<Node> st;	
	int n;
	
	SegmentTree(int n) : n(n) { st.resize(4 * n + 5); build(1, 1, n); }
	
	void build(int head, int l, int r)
	{
		if (l == r)
		{
			st[head] = Node(arr[l]);
			return;
		}
		
		int mid = l + r >> 1;
		build(2 * head, l, mid);
		build(2 * head + 1, mid + 1, r);
		
		st[head] = st[2 * head] + st[2 * head + 1];
	}
	
	void update(int head, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			st[head] = val;
			return;
		}
		
		int mid = l + r >> 1;
		if (pos <= mid)
			update(2 * head, l, mid, pos, val);
		else
			update(2 * head + 1, mid + 1, r, pos, val);
		
		st[head] = st[2 * head] + st[2 * head + 1];
	}
	void update(int pos, int val) { update(1, 1, n, pos, val); }
	
	Node query(int head, int l, int r, int u, int v) 
	{
		if (l > v || r < u) return Node(oo);
		if (u <= l && r <= v) return st[head];
		
		int mid = l + r >> 1;
		return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
	}
	int query(int u, int v) { return query(1, 1, n, u, v).finals; }
};
 
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
	
	SegmentTree seg(n);
	
	cin >> m;
	while (m--)
	{
		int type; cin >> type;
		
		if (type == 0)
		{
			int x, y; cin >> x >> y;
			seg.update(x, y);
		} else
		{
			int u, v; cin >> u >> v;
			cout << seg.query(u, v) << '\n';
		}
	}
 
	return 0;
}
