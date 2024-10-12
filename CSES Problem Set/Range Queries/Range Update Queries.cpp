#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pll pair<long long, long long>
#define vll vector<long long>
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define vc vector<char>
#define vi vector<int>
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
const ll inf = 1e18 + 9;
int a[maxn];
ll st[4 * maxn], lazy[4 * maxn];
int n, q;
 
void pass(int head)
{
	if (!lazy[head]) return;
	
	st[2 * head] += lazy[head];
	st[2 * head + 1] += lazy[head];
	lazy[2 * head] += lazy[head];
	lazy[2 * head + 1] += lazy[head];
	lazy[head] = 0; 
}
 
void build(int head, int l, int r)
{
	if (l == r)
	{
		st[head] = a[l]; 
		return;
	}
	
	int mid = l + r >> 1;
	build(2 * head, l, mid);
	build(2 * head + 1, mid + 1, r);
	
	st[head] = min(st[2 * head], st[2 * head + 1]);
}
 
void update(int head, int l, int r, int u, int v, int val)
{
	if (l > v || r < u) return;
	
	if (u <= l && r <= v)
	{
		lazy[head] += val;
		st[head] += val;
		return;
	}
	
	int mid = l + r >> 1;
	pass(head);
	update(2 * head, l, mid, u, v, val);
	update(2 * head + 1, mid + 1, r, u, v, val);
	
	st[head] = min(st[2 * head], st[2 * head + 1]);
}
 
ll get(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return inf;
	
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	pass(head);
	return min(get(2 * head, l, mid, u, v), get(2 * head + 1, mid + 1, r, u, v));
}
 
void input()
{
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	
	while (q--)
	{
		int type, x; cin >> type >> x;
		
		if (type == 1)
		{
			int y, z; cin >> y >> z;
			update(1, 1, n, x, y, z);
		} else 
			cout << get(1, 1, n, x, x) << '\n';
		
	}	
 
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
	
	return 0;
}
