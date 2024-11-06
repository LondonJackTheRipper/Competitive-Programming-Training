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

class SegmentTree
{
private:
	vector<int> st; 
	
	void update(int head, int l, int r, int pos)
	{
		if (pos < l || r < pos) return;
		if (l == r)
		{
			st[head] ^= 1;
			return;	
		}	
		
		int mid = l + r >> 1;
		update(2 * head, l, mid, pos);
		update(2 * head + 1, mid + 1, r, pos);
		
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
	int n;
	
	SegmentTree(int n = 0) : n(n)
	{
		st.resize(segsize, 0);
	}
	
	void update(int pos) { update(1, 1, n, pos); }
	int query(int u, int v) { return query(1, 1, n, u, v); }
};

int n, q;
string s;

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	cin >> s;
	int n = s.length();
	s = " " + s;
	SegmentTree seg[30];
	for (int i = 0; i < 26; i++)
		seg[i] = SegmentTree(n);
	for (int i = 1; i <= n; i++)
		seg[s[i] - 'a'].update(i);
	
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		
		if (type == 1)
		{
			int pos; cin >> pos;
			char c; cin >> c;
			
			seg[s[pos] - 'a'].update(pos);
			seg[c - 'a'].update(pos);
			s[pos] = c;
		} else
		{
			int u, v; cin >> u >> v;
			
			int res = 0;
			for (int i = 0; i < 26; i++)
				res += (seg[i].query(u, v) > 0);
			cout << res << '\n';
		}
	}

	return 0;
}
