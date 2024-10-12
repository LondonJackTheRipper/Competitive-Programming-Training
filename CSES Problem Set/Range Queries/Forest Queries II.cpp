#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 1009;
const int segsize = 4 * maxn;
 
int arr[maxn][maxn];
int st[segsize][segsize];
int n, q;
 
void build_col(int idx, int lx, int rx, int idy, int ly, int ry)
{
	if (ly == ry)
		if (lx == rx)
			st[idx][idy] = arr[lx][ly];
		else
			st[idx][idy] = st[2 * idx][idy] + st[2 * idx + 1][idy];
	else
	{
		int mid = ly + ry >> 1;
		build_col(idx, lx, rx, 2 * idy, ly, mid);
		build_col(idx, lx, rx, 2 * idy + 1, mid + 1, ry);
		st[idx][idy] = st[idx][2 * idy] + st[idx][2 * idy + 1];
	}
}
 
void build_row(int idx, int lx, int rx)
{
	if (lx != rx)
	{
		int mid = lx + rx >> 1;
		build_row(2 * idx, lx, mid);
		build_row(2 * idx + 1, mid + 1, rx);
	}
	build_col(idx, lx, rx, 1, 1, n);
}
 
void update_col(int idx, int lx, int rx, int idy, int ly, int ry, int x, int y)
{
	if (ly == ry)
		if (lx == rx)
			st[idx][idy] ^= 1;
		else
			st[idx][idy] = st[2 * idx][idy] + st[2 * idx + 1][idy];
	else
	{
		int mid = ly + ry >> 1;
		if (y <= mid)
			update_col(idx, lx, rx, 2 * idy, ly, mid, x, y);
		else
			update_col(idx, lx, rx, 2 * idy + 1, mid + 1, ry, x, y);
		st[idx][idy] = st[idx][2 * idy] + st[idx][2 * idy + 1];
	}
}
 
void update_row(int idx, int lx, int rx, int x, int y)
{
	if (lx != rx)
	{
		int mid = lx + rx >> 1;
		if (x <= mid)
			update_row(2 * idx, lx, mid, x, y);
		else
			update_row(2 * idx + 1, mid + 1, rx, x, y);
	}
	update_col(idx, lx, rx, 1, 1, n, x, y);
}
 
int query_col(int idx, int idy, int ly, int ry, int y1, int y2)
{
	if (y1 > y2) 
		return 0;
	if (ly == y1 && ry == y2)
		return st[idx][idy];
	int mid = ly + ry >> 1;
	int res1 = query_col(idx, 2 * idy, ly, mid, y1, min(y2, mid));
	int res2 = query_col(idx, 2 * idy + 1, mid + 1, ry, max(y1, mid + 1), y2);
	return res1 + res2;
}
 
int query_row(int idx, int lx, int rx, int x1, int x2, int y1, int y2)
{
	if (x1 > x2) 
		return 0;
	if (lx == x1 && rx == x2)
		return query_col(idx, 1, 1, n, y1, y2);
	int mid = lx + rx >> 1;
	int res1 = query_row(2 * idx, lx, mid, x1, min(x2, mid), y1, y2);
	int res2 = query_row(2 * idx + 1, mid + 1, rx, max(x1, mid + 1), x2, y1, y2);
	return res1 + res2;
}
 
signed main()
{
	faster();
 
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)	
		{
			char c; cin >> c;
			if (c == '*') arr[i][j] = 1;
		}
	build_row(1, 1, n);
	
	while (q--)
	{
		int type; cin >> type;
		
		if (type == 1)
		{
			int x, y;
			cin >> x >> y;
			update_row(1, 1, n, x, y);
		} else
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << query_row(1, 1, n, x1, x2, y1, y2) << '\n';
		}
	}
 
	return 0;
}
