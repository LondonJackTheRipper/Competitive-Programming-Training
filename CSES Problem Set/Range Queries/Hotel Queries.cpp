#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
int arr[maxn], st[4 * maxn];
int n, m;
 
void build(int head, int l, int r)
{
	if (l == r)
	{
		st[head] = arr[l];
		return;
	}
	
	int mid = l + r >> 1;
	build(2 * head, l, mid);
	build(2 * head + 1, mid + 1, r);
	st[head] = max(st[2 * head], st[2 * head + 1]);
}
 
void query(int head, int l, int r, int val)
{
	if (l == r)
	{
		cout << l << ' ';
		st[head] = arr[l] - val;
		arr[l] -= val;
		return;
	}
	
	int mid = l + r >> 1;
	if (st[2 * head] >= val)
		query(2 * head, l, mid, val);
	else 
		query(2 * head + 1, mid + 1, r, val);
	st[head] = max(st[2 * head], st[2 * head + 1]);
}
 
void input()
{	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build(1, 1, n);
	
	while (m--)
	{
		int x; cin >> x;
		
		if (st[1] < x)
			cout << 0 << ' ';
		else
			query(1, 1, n, x);
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
