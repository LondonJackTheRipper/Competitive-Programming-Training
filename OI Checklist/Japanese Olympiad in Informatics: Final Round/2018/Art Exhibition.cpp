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
const int maxn = 5e5 + 9;
 
int n;
ll pre[maxn];
pair<ll, ll> a[maxn];
 
ll segment(int l, int r) { return (l <= r ? pre[r] - pre[l - 1] : 0); }
 
struct SegmentTree
{
	int n;
	vector<ll> st;
	
	SegmentTree(int n) : n(n) { st.resize(4 * n + 5, 0); build(1, 1, n); }
	
	void build(int head, int l, int r)
	{
		if (l == r)
		{
			st[head] = a[l].first + segment(l, n);
			return;
		}
		
		int mid = l + r >> 1;
		build(2 * head, l, mid);
		build(2 * head + 1, mid + 1, r);
		
		st[head] = max(st[2 * head], st[2 * head + 1]);
	}
	
	ll query(int head, int l, int r, int u, int v)
	{
		if (l > v || r < u) return -oo;
		if (u <= l && r <= v) return st[head];
		
		int mid = l + r >> 1;
		return max(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
	}
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
 
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second; 
	// first: size
	// second: value
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].second;
        
	SegmentTree seg(n);
	
	ll ans = -oo;                           
	for (int i = 1; i <= n; i++)
		ans = max(ans, seg.query(1, i) - a[i].first - segment(i + 1, n));
	cout << ans << '\n';                                                                               
 	
  	return 0;
}
