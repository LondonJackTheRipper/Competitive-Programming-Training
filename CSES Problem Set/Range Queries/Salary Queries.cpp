#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int oo = 1e9 + 7;
const int maxn = 6e5 + 9;
const int segsize = 4 * maxn;
 
struct Query
{
	char type;
	int x, y;
	
	Query(char type, int x, int y) : type(type), x(x), y(y) {}
};
 
class SegmentTree
{
private:
	vector<int> st;
	int n;
	
	void update(int head, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			st[head] += val;
			return;
		}
		
		int mid = l + r >> 1;
		if (pos <= mid)
			update(2 * head, l, mid, pos, val);
		else
			update(2 * head + 1, mid + 1, r, pos, val);
		
		st[head] = st[2 * head] + st[2 * head + 1];
	}
	
	int query(int head, int l, int r, int u, int v)
	{
		if (l > v || r < u) return 0;
		if (u <= l && r <= v) return st[head];
		
		int mid = l + r >> 1;
		return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
	}
public:
	SegmentTree(int n) : n(n) { st.resize(segsize, 0); }
	
	void update(int pos, int val = 1) { update(1, 1, n, pos, val); }
	int query(int u, int v) { return query(1, 1, n, u, v); }
};
 
int n, q;
int arr[maxn];
vector<Query> queries;
unordered_map<int, int> compress;
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n >> q;
	
	// compression
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		v.push_back(arr[i]);
	}
	while (q--)
	{
		char type; cin >> type;
		int x, y; cin >> x >> y;
		if (type == '?') v.push_back(x);
		v.push_back(y);
		
		queries.push_back({type, x, y});
	}
	sort(v.begin(), v.end());
	int compression = 0;
	for (int x : v)
		if (!compress[x])
			compress[x] = ++compression;
			
	SegmentTree seg(compression);
	for (int i = 1; i <= n; i++) seg.update(compress[arr[i]]);
	
	for (Query q : queries)
	{
		char type = q.type;
	
		if (type == '!')
		{
			int val = q.y;
			seg.update(compress[val]);
			seg.update(compress[arr[q.x]], -1);
			arr[q.x] = val;
		} else
		{
			int x = q.x;
			int y = q.y;
			
			cout << seg.query(compress[x], compress[y]) << '\n';
		}
	}
 
	return 0;
}
