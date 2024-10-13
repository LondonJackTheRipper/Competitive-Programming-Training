#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll oo = 1e18;
const int maxn = 2e5 + 9;

int n, q;
ll arr[maxn];

struct SegmentTree
{
	struct Node
	{
		ll sum, mn, lazy;
		
		Node(ll val = 0) : sum(val), mn(val), lazy(0) {}
		
		Node operator + (const Node &other)
		{
			if (sum == oo) return other;
			if (other.sum == oo) return *this;
			Node res;
			res.sum = sum + other.sum;
			res.mn = min(mn, other.mn);
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
	
	void pass(int head, int l, int r)
	{
		if (st[head].lazy == 0) return;
		
		ll &v = st[head].lazy;
		st[head].mn += v;
		st[head].sum += (r - l + 1) * v;
		
		if (l != r)
		{
			st[2 * head].lazy += v;
			st[2 * head + 1].lazy += v;
		}
		
		v = 0;
	}
	
	void update(int head, int l, int r, int u, int v, ll C)
	{
		pass(head, l, r);
		if (l > v || r < u) return;
		if (u <= l && r <= v)
		{
			st[head].lazy += C;
			pass(head, l, r);
			return;
		}
		
		int mid = l + r >> 1;
		update(2 * head, l, mid, u, v, C);
		update(2 * head + 1, mid + 1, r, u, v, C);
		
		st[head] = st[2 * head] + st[2 * head + 1];
	}
	void update(int u, int v, ll C) { update(1, 1, n, u, v, C); }
	
	Node query(int head, int l, int r, int u, int v)
	{
		pass(head, l, r);
		if (l > v || r < u) return Node(oo);
		if (u <= l && r <= v) return st[head];
		
		int mid = l + r >> 1;
		return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
	}
	ll query(int u, int v, char type) 
	{
		Node qr = query(1, 1, n, u, v);
		return (type == 'M' ? qr.mn : qr.sum);
	}
};

signed main()
{
	if (fopen("haybales.in", "r"))
	{
		freopen("haybales.in", "r", stdin);
		freopen("haybales.out", "w", stdout);
	}
	faster();

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	SegmentTree seg(n);
	
	while (q--)
	{
		char type; cin >> type;
		
		if (type == 'P')
		{
			int u, v; cin >> u >> v;
			ll C; cin >> C;
			seg.update(u, v, C);
		} else
		{
			int u, v; cin >> u >> v;
			cout << seg.query(u, v, type) << '\n';
		}
	}

	return 0;
}

