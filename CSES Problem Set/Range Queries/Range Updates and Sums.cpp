#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back
 
const int maxn = 200009;
 
ll st[4 * maxn], add[4 * maxn], assign[4 * maxn];
bool flag[4 * maxn];
int t[maxn];
int n, m;
 
void pass(int head, int l, int r)
{
	if (flag[head] == true)
	{
		st[head] = (r - l + 1) * assign[head];
		if (l != r)
		{
			assign[2 * head] = assign[head];
			assign[2 * head + 1] = assign[head];
			add[2 * head] = 0;
			add[2 * head + 1] = 0;
			flag[2 * head] = true;
			flag[2 * head + 1] = true;
		}
		assign[head] = 0; 
		flag[head] = false;
	}
	if (add[head])
	{
		st[head] += (r - l + 1) * add[head];
		if (l != r)
		{
			add[2 * head] += add[head];
			add[2 * head + 1] += add[head];
		}
		add[head] = 0;
	}
}
 
void build(int head, int l, int r)
{
	if (l == r)
	{
		st[head] = t[l];
		return;
	}
	
	int mid = l + r >> 1;
	build(2 * head, l, mid);
	build(2 * head + 1, mid + 1, r);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
void addition(int head, int l, int r, int u, int v, int val)
{
	pass(head, l, r);
	if (l > v || r < u) return;
	if (u <= l && r <= v)
	{
		add[head] += val;
		pass(head, l, r);
		return;
	}
	
	int mid = l + r >> 1;
	addition(2 * head, l, mid, u, v, val);
	addition(2 * head + 1, mid + 1, r, u, v, val);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
void assignment(int head, int l, int r, int u, int v, int val)
{
	pass(head, l, r);
	if (l > v || r < u) return;
	if (u <= l && r <= v)
	{
		assign[head] = val;
		flag[head] = true;
		add[head] = 0;
		pass(head, l, r);
		return;
	}
	
	int mid = l + r >> 1;
	assignment(2 * head, l, mid, u, v, val);
	assignment(2 * head + 1, mid + 1, r, u, v, val);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
ll query(int head, int l, int r, int u, int v)
{
	pass(head, l, r);
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return st[head];
	int mid = l + r >> 1;
	
	return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
}
 
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> t[i];
	build(1, 1, n);
	
	while (m--)
	{
		int type, x, y, z; cin >> type >> x >> y;
		
		if (type == 2)
		{
			cin >> z;
			assignment(1, 1, n, x, y, z);
		} else if (type == 1)
		{
			cin >> z;
			addition(1, 1, n, x, y, z);
		} else 
			cout << query(1, 1, n, x, y) << '\n';
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
