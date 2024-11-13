#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 39999;
 
int a[maxn], id[maxn];
int n, q;
int st[4 * maxn];
 
struct query
{
	int k, num;
	int l, r;
	
	query(int kk = 0, int nu = 0, int lll = 0, int rr = 0)
	{
		k = kk;
		num = nu;
		l = lll;
		r = rr;
	}
};
 
bool operator < (const query& a, const query& b)
{
	return a.k < b.k;
}
 
void build(int head, int l, int r)
{
	if (l == r)
	{
		st[head] = 1;
		return;
	}
	
	int mid = l + r >> 1;
	build(2 * head, l, mid);
	build(2 * head + 1, mid + 1, r);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
void update(int head, int l, int r, int pos)
{
	if (pos < l || r < pos) return;
	if (l == r)
	{
		st[head] = 0;
		return;
	}
	
	int mid = l + r >> 1;
	update(2 * head, l, mid, pos);
	update(2 * head + 1, mid + 1, r, pos);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
int get(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	return get(2 * head, l, mid, u, v) + get(2 * head + 1, mid + 1, r, u, v);
}
 
void input()
{
	cin >> n;
	
	vector<pair<int, int>> arr(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		arr[i].first = a[i];
		arr[i].second = i;
	}
	sort(arr.begin() + 1, arr.end());
	for (int i = 1; i <= n; i++)	
		id[i] = arr[i].second;
		
	cin >> q;
	vector<query> queries;
	int cnt = 0;
	while (q--)
	{
		int i, j, k; cin >> i >> j >> k;
		queries.pb(query(k, ++cnt, i, j));
	}
	sort(queries.begin(), queries.end());
	build(1, 1, n);
	int i = 1;
	vector<int> b(n + 1, 1);
	vector<pair<int, int>> res;
	for (query Q : queries)
	{
		while (i <= n && a[id[i]] <= Q.k)
		{
			b[i] = 0;
			update(1, 1, n, id[i]);
			i++;
		}
		res.pb({Q.num, get(1, 1, n, Q.l, Q.r)});	
	}
	sort(res.begin(), res.end());
	
	for (auto it : res)
		cout << it.second << '\n';
}
 
int main()
{
	faster();
	input();
 
	return 0;
}
 
