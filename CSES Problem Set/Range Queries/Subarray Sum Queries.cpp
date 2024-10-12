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
 
int n, m;
ll arr[maxn];
 
class SegmentTree
{
private:
	struct Node
	{
		ll pre, suff, finals, sum;
		
		Node(ll val = 0) : sum(val)
		{
			ll tmp = max(0ll, val);
			pre = suff = finals = tmp;	
		}	
		
		Node operator + (const Node& other)
		{
			Node res;
			res.pre = max(pre, sum + other.pre);
			res.suff = max(other.suff, other.sum + suff);
			res.finals = max({finals, other.finals, suff + other.pre});
			res.sum = sum + other.sum;
			return res;
		}
	};	
	
	vector<Node> st;
	int n;
	
	void build(int head, int l, int r, ll *arr)
	{
		if (l == r)
		{
			st[head] = Node(arr[l]);
			return;
		}
		
		int mid = l + r >> 1;
		build(2 * head, l, mid, arr);
		build(2 * head + 1, mid + 1, r, arr);
		
		st[head] = st[2 * head] + st[2 * head + 1];
	}
	
	void update(int head, int l, int r, int pos, ll val)
	{
		if (l == r)
		{
			st[head] = Node(val);
			return;
		}
		
		int mid = l + r >> 1;
		if (pos <= mid)
			update(2 * head, l, mid, pos, val);
		else
			update(2 * head + 1, mid + 1, r, pos, val);
			
		st[head] = st[2 * head] + st[2 * head + 1];
	}
public:
	SegmentTree(int n, ll *arr) : n(n)
	{
		st.resize(segsize);
		build(1, 1, n, arr);
	}
	
	void update(int pos, ll val) { update(1, 1, n, pos, val); }
	ll get() { return st[1].finals; }
};
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	SegmentTree seg(n, arr);
	
	while (m--)
	{
		int k; cin >> k;
		ll x; cin >> x;
		
		seg.update(k, x);
		
		cout << seg.get() << '\n';
	}
 
	return 0;
}
