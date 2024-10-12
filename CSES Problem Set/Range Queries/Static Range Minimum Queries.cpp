#include<bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
#define ll long long
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define fi first
#define la last
 
const int inf = 1e9 + 7;
const int maxn = 1e5;
int a[2 * maxn + 9], mn[8 * maxn + 9];
int n, q;
 
void build(int head, int l, int r)
{
	if (l == r)
	{
		mn[head] = a[l];
		return;
	}
	
	int mid = l + r >> 1;
	build(2 * head, l, mid);
	build(2 * head + 1, mid + 1, r);
	
	mn[head] = min(mn[2 * head], mn[2 * head + 1]);
}
 
int get(int head, int l, int r, int u, int v)
{
	if (r < u || l > v) return inf;
	
	if (u <= l && r <= v) return mn[head];
	
	int mid = l + r >> 1;
	int ans1 = get(2 * head, l, mid, u, v);
	int ans2 = get(2 * head + 1, mid + 1, r, u, v);
	
	return min(ans1, ans2);
}
 
void input()
{
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	
	while (q--)
	{
		int u, v; cin >> u >> v;
		cout << get(1, 1, n, u, v) << '\n';
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	input();
	
    return 0;
}
