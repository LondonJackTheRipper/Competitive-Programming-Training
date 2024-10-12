#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
 
int st[4 * maxn];
int arr[maxn];
int n;
 
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
	if (l == r)
	{
		st[head] ^= 1;
		return;
	}
	
	int mid = l + r >> 1;
	if (pos <= mid)
		update(2 * head, l, mid, pos);
	else
		update(2 * head + 1, mid + 1, r, pos);
	
	st[head] = st[2 * head] + st[2 * head + 1];
}
 
int query(int head, int l, int r, int k)
{
	if (l == r) return l;
	
	int mid = l + r >> 1;
	if (st[2 * head] < k)
		return query(2 * head + 1, mid + 1, r, k - st[2 * head]);
	else
		return query(2 * head, l, mid, k);
}
 
int main()
{
	faster();
 
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build(1, 1, n);
	
	for (int i = 1; i <= n; i++)
	{
		int p; cin >> p;
		
		int pos = query(1, 1, n, p);
		cout << arr[pos] << ' ';
		update(1, 1, n, pos);
 	}
 
	return 0;
}
