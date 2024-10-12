#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
 
  Mua Code nhu mua Florentino !!
  
  Tags:
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
 
ll st1[4 * maxn], st2[4 * maxn];
ll lazy1[4 * maxn], lazy2[4 * maxn];
ll arr[maxn], pre[maxn];
int n, m; 
 
ll segment(int l, int r)
{
	return pre[r] - pre[l - 1];
}
 
// TREE 1
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
 
void pass1(int head, int l, int r)
{
	if (lazy1[head] == 0 || l == r) return;
	
	lazy1[2 * head] += lazy1[head];
	lazy1[2 * head + 1] += lazy1[head];
	int mid = l + r >> 1;
	st1[2 * head] += (mid - l + 1) * lazy1[head];
	st1[2 * head + 1] += (r - mid) * lazy1[head];
	
	lazy1[head] = 0; 
}
 
void update1(int head, int l, int r, int u, int v, ll val)
{
	if (l > v || r < u) return;
	if (u <= l && r <= v) 
	{
		st1[head] += (r - l + 1) * val;
		lazy1[head] += val;
		return;
	}
	
	int mid = l + r >> 1;
	pass1(head, l, r);
	update1(2 * head, l, mid, u, v, val);
	update1(2 * head + 1, mid + 1, r, u, v, val);
	
	st1[head] = st1[2 * head] + st1[2 * head + 1];
}
 
ll query1(int head, int l, int r, int u, int v)
{
	pass1(head, l, r);
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return st1[head];
	
	int mid = l + r >> 1;
	return query1(2 * head, l, mid, u, v) + query1(2 * head + 1, mid + 1, r, u, v);
}
 
// TREE 2
void pass2(int head, int l, int r)
{
	if (lazy2[head] == 0 || l == r) return;
	
	lazy2[2 * head] += lazy2[head];
	lazy2[2 * head + 1] += lazy2[head];
	int mid = l + r >> 1;
	st2[2 * head] += segment(l, mid) * lazy2[head];
	st2[2 * head + 1] += segment(mid + 1, r) * lazy2[head];
	
	lazy2[head] = 0;
}
 
void update2(int head, int l, int r, int u, int v, ll val)
{
	if (l > v || r < u) return;
	if (u <= l && r <= v)
	{
		st2[head] += segment(l, r) * val;
		lazy2[head] += val;
		return;
	}
	
	int mid = l + r >> 1;
	pass2(head, l, r);
	update2(2 * head, l, mid, u, v, val);
	update2(2 * head + 1, mid + 1, r, u, v, val);
	
	st2[head] = st2[2 * head] + st2[2 * head + 1];
}
 
ll query2(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	pass2(head, l, r);
	if (u <= l && r <= v) return st2[head];
	
	int mid = l + r >> 1;
	return query2(2 * head, l, mid, u, v) + query2(2 * head + 1, mid + 1, r, u, v);
} 
 
int main()
{
	faster();
 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) pre[i] = i + pre[i - 1];
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build1(1, 1, n);
	
	while (m--)
	{
		int type, a, b; cin >> type >> a >> b;
		
		if (type == 1)
		{
			update1(1, 1, n, a, b, -a + 1);
			update2(1, 1, n, a, b, 1);
		} else
			cout << query1(1, 1, n, a, b) + query2(1, 1, n, a, b) << '\n';
	}
	
	return 0;
}
