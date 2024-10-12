#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 2e5 + 9;
const int segsize = 4 * maxn;
 
vector<tuple<int, int, int>> queries;
ll pre[maxn], ans[maxn];
int x[maxn];
int n, q;
 
ll segment(int l, int r) { return pre[r] - pre[l - 1]; }
 
class SegmentTree
{
private:
	struct Node
	{
		int mx, lazy;
		ll sum;
		
		Node(int mx = -1e9 - 8, int lazy = -1, ll sum = 0) : mx(mx), lazy(lazy), sum(sum) {}
		
		Node operator + (const Node& other)
		{
			Node res;
			res.mx = max(mx, other.mx);
			res.lazy = -1;
			res.sum = sum + other.sum;
			return res;
		}
	};	
	
	vector<Node> st;
	int n;
	
	void pass(int head, int l, int r)
	{
		if (st[head].lazy == -1 || l == r) return;
		
		int mid = l + r >> 1;
		st[2 * head].sum = 1ll * (mid - l + 1) * st[head].lazy;
		st[2 * head + 1].sum = 1ll * (r - mid) * st[head].lazy;
		st[2 * head].mx = st[2 * head + 1].mx = st[head].lazy;
		st[2 * head].lazy = st[2 * head + 1].lazy = st[head].lazy;
		
		st[head].lazy = -1; 
	}
	
	void update(int head, int l, int r, int u, int v, int val)
	{
		pass(head, l, r);
		if (u > v) return;
		if (l > v || r < u) return;
		if (u <= l && r <= v) 
		{
			st[head].mx = val;
			st[head].sum = 1ll * (r - l + 1) * val;
			st[head].lazy = val;
			return;
		}
		
		int mid = l + r >> 1;
		update(2 * head, l, mid, u, v, val);
		update(2 * head + 1, mid + 1, r, u, v, val);
		
		st[head] = st[2 * head] + st[2 * head + 1];
	}
	
	int getpos(int head, int l, int r, int left, int k) // >= k
	{
		pass(head, l, r);
		if (l == r)
			return ((l < left || st[head].mx < k) ? n + 1 : l); 
		
		int mid = l + r >> 1;
		int q1 = 1e9, q2 = 1e9;
		if (st[2 * head].mx >= k && mid >= left)
		{
			q1 = getpos(2 * head, l, mid, left, k);
			if (q1 == n + 1)
				q2 = getpos(2 * head + 1, mid + 1, r, left, k);
		}
		else
			q2 = getpos(2 * head + 1, mid + 1, r, left, k);
			
		return min(q1, q2);
	}
	
	ll query(int head, int l, int r, int u, int v)
	{
		pass(head, l, r);
		if (l > v || r < u) return 0ll;
		if (u <= l && r <= v) return st[head].sum;
		
		int mid = l + r >> 1;
		return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
	}
public:
	SegmentTree (int n) : n(n) { st.resize(segsize); }
	
	void update(int u, int v, int val) { update(1, 1, n, u, v, val); }
	int getpos(int l, int k) { return getpos(1, 1, n, l, k); }
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
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		pre[i] = pre[i - 1] + x[i];
	}
 
	for (int i = 1; i <= q; i++)
	{
		int a, b; cin >> a >> b;
		queries.push_back(make_tuple(a, b, i));	
	}	
	sort(queries.begin(), queries.end(), greater<tuple<int, int, int>>());
	
	SegmentTree seg(n);
	int curl = n;
	
	for (tuple<int, int, int> tp : queries)
	{
		int a = get<0>(tp);
		int b = get<1>(tp);
		int id = get<2>(tp);
		
		while (a <= curl)
		{
			int pos = seg.getpos(curl + 1, x[curl]);
			seg.update(curl, pos - 1, x[curl]);
			curl--;
		}
		
		ans[id] = seg.query(a, b) - segment(a, b);
	}
	
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';
	
	return 0;
}
