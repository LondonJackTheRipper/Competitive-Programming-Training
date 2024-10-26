#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 1e6 + 9;

struct Node 
{
    int optimal;
    int open;
    int close;

    Node(int opt = 0, int o = 0, int c = 0) 
	{ 
        optimal = opt;
        open = o;
        close = c;
    }
};

Node st[4 * maxn];
Node operator + (const Node& left, const Node& right)
{
	Node res;
	
	int tmp = min(left.open, right.close);
	
	res.optimal = left.optimal + right.optimal + 2 * tmp;
	
	res.open = left.open + right.open - tmp;
	res.close = left.close + right.close - tmp;
	return res;
}

string s;
int q;

void build(int head, int l, int r)
{
	if (l == r)
	{
		if (s[l] == '(') st[head] = Node(0, 1, 0);
		else st[head] = Node(0, 0, 1);
		return;
	}
	
	int mid = l + r >> 1;
	build(2 * head, l, mid);
	build(2 * head + 1, mid + 1, r);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}

Node get(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return Node(0, 0, 0);
	if (u <= l && r <= v) return st[head];
	
	int mid = l + r >> 1;
	return get(2 * head, l, mid, u, v) + get(2 * head + 1, mid + 1, r, u, v);
}

void input()
{
	cin >> s; s = " " + s;
	int n = s.length() - 1;
	build(1, 1, n);
	
	cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		
		cout << get(1, 1, n, l, r).optimal << '\n';
	}
}

int main()
{
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
	faster();

	input();

	return 0;
}
