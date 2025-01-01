#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 1e5 + 9;
const int segsize = 4 * maxn;

class Segment_Tree
{
private:
	vector<int> st;
	vector<int> lazy;
	
	void build(int head, int l, int r, int *arr)
	{
		if (l == r)
		{
			st[head] = (arr[l] >> this->id & 1);
			return;
		}
		
		int mid = l + r >> 1;
		build(2 * head, l, mid, arr);
		build(2 * head + 1, mid + 1, r, arr);
		
		st[head] = st[2 * head] + st[2 * head + 1];
	}
	
	void pass(int head, int l, int r)
	{
		if (lazy[head] == 0 || l == r) return;
		
		lazy[2 * head] ^= 1;
		lazy[2 * head + 1] ^= 1;
		int mid = l + r >> 1;
		st[2 * head] = (mid - l + 1) - st[2 * head];
		st[2 * head + 1] = (r - mid) - st[2 * head + 1];
		
		lazy[head] = 0;
	}
	
	void update(int head, int l, int r, int u, int v)
	{
		if (l > v || r < u) return;
		if (u <= l && r <= v)
		{
			st[head] = (r - l + 1) - st[head];
			lazy[head] ^= 1;
			
			return;
		}
		
		int mid = l + r >> 1;
		pass(head, l, r);
		update(2 * head, l, mid, u, v);
		update(2 * head + 1, mid + 1, r, u, v);
		
		st[head] = st[2 * head] + st[2 * head + 1];
	}
	
	int query(int head, int l, int r, int u, int v)
	{
		pass(head, l, r);
		if (l > v || r < u) return 0;
		if (u <= l && r <= v) return st[head];
		
		int mid = l + r >> 1;
		return query(2 * head, l, mid, u, v) + query(2 * head + 1, mid + 1, r, u, v);
	}
public:
	int n;
	int id;
	
	void build(int n, int id, int *arr) 
	{
		this->n = n;
		this->id = id;
		st.resize(segsize, 0);
		lazy.resize(segsize, 0);
		build(1, 1, n, arr);
	}
	
	void update(int u, int v) { update(1, 1, n, u, v); }
	ll query(int u, int v) { return query(1, 1, n, u, v); }
};

int arr[maxn];
int n, m;

signed main()
{
   faster();

	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> arr[i];
	Segment_Tree seg[22];
	for (int i = 0; i < 21; i++)
		seg[i].build(n, i, arr);
	
	cin >> m;
	while (m--)
	{
		int type; cin >> type;
		
		if (type == 1)
		{
			int u, v; cin >> u >> v;
			ll res = 0;
			for (int i = 0; i < 21; i++)	
				res = res + (1 << i) * seg[i].query(u, v);
			cout << res << '\n';
		} else
		{
			int u, v; cin >> u >> v;
			ll val; cin >> val;
			for (int i = 0; i < 21; i++)
				if (val >> i & 1)
					seg[i].update(u, v);
		}
	}

	return 0;
}
