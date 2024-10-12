#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
const ll oo = 1e18;
 
ll st[4 * maxn], lazy[4 * maxn];
ll st1[4 * maxn];
ll arr[maxn], pre[maxn];
int n, q;
 
// tree 1
void build(int head, int l, int r)
{
	if (l == r)
	{
		st[head] = pre[l];
		return;
	}
	
	int mid = l + r >> 1;
	build(2 * head, l, mid);
	build(2 * head + 1, mid + 1, r);
	
	st[head] = max(st[2 * head], st[2 * head + 1]);
}
 
void pass(int head, int l, int r)
{
	if (l == r || lazy[head] == 0) return;
	
	lazy[2 * head] += lazy[head];
	lazy[2 * head + 1] += lazy[head];
	st[2 * head] += lazy[head];
	st[2 * head + 1] += lazy[head];
	
	lazy[head] = 0; 
}
 
void update(int head, int l, int r, int u, int v, ll val)
{
	if (l > v || r < u) return;
	if (u <= l && r <= v)
	{
		st[head] += val;
		lazy[head] += val;
		return;	
	}
	
	int mid = l + r >> 1;
	pass(head, l, r);
	update(2 * head, l, mid, u, v, val);
	update(2 * head + 1, mid + 1, r, u, v, val);
	
	st[head] = max(st[2 * head], st[2 * head + 1]);
}
 
ll query(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return -oo;
	pass(head, l, r);
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	return max(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
}
 
// tree 2
void build1(int head, int l, int r)
{
	if (l == r)
	{
		st1[head] = arr[l];
		return;
	}
	
	int mid = l + r >> 1;
	build1(2 * head, l, mid);
	build1(2 * head + 1, mid + 1, r);
	
	st1[head] = st1[2 * head] + st1[2 * head + 1];
}
 
void update1(int head, int l, int r, int pos, ll val)
{
	if (l == r)
	{
		st1[head] = val;
		return;
	}
	
	int mid = l + r >> 1;
	if (pos <= mid)
		update1(2 * head, l, mid, pos, val);
	else
		update1(2 * head + 1, mid + 1, r, pos, val);
		
	st1[head] = st1[2 * head] + st1[2 * head + 1];
}
 
ll query1(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return st1[head];
	
	int mid = l + r >> 1;
	return query1(2 * head, l, mid, u, v) + query1(2 * head + 1, mid + 1, r, u, v);
}
 
int main()
{
	faster();
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	build(1, 1, n);
	build1(1, 1, n);
	
	while (q--)
	{
		int type; cin >> type;
 
		if (type == 1)
		{
			int k, u; cin >> k >> u;
			update(1, 1, n, k, n, u - arr[k]);
			update1(1, 1, n, k, u);
			arr[k] = u;	
		} else
		{
			int a, b; cin >> a >> b;
			cout << max(0ll, query(1, 1, n, a, b) - (a == 1 ? 0 : query1(1, 1, n, 1, a - 1))) << '\n';
		}
	}
 
	return 0;
}
