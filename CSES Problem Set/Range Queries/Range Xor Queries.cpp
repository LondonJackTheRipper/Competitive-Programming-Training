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
int a[maxn], xo[4 * maxn];
int n, q;
 
void build(int head, int l, int r)
{
	if (l == r)
	{
		xo[head] = a[l];
		return;
	}
	
	int mid = l + r >> 1;
	build(2 * head, l, mid);
	build(2 * head + 1, mid + 1, r);
	
	xo[head] = (xo[2 * head] ^ xo[2 * head + 1]);
}
 
int get(int head, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	
	if (u <= l && r <= v) return xo[head];
	
	int mid = l + r >> 1;
	int ans1 = get(2 * head, l, mid, u, v);
	int ans2 = get(2 * head + 1, mid + 1, r, u, v);
	
	return (ans1 ^ ans2);
	
}
 
void input()
{
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	
	while (q--)
	{
		int x, y; cin >> x >> y;
		
		cout << get(1, 1, n, x, y) << '\n';
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	input();
	
	return 0;
}
