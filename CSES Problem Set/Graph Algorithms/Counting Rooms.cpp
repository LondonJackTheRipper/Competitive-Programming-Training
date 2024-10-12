#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define fi first
#define la last
 
int a[1001][1001];
int x[4] = {-1, 0, 0, 1};
int y[4] = {0, -1, 1, 0};
 
void loang(int i, int j, int n, int m)
{
	for (int k = 0; k < 4; k++)
	{
		int l = i + x[k];
		int r = j + y[k];
		
		if (1 <= l && l <= n && 1 <= r && r <= m && a[l][r])
		{
			a[l][r] = 0;
			loang(l, r, n, m);
		}
	}
}
 
void input()
{
	int n, m; cin >> n >> m;
	char x;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
		{
			cin >> x;
			if (x == '.') a[i][j] = 1; else a[i][j] = 0;
		}
		
	int ans = 0;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) if (a[i][j])
		{
			ans++;
			loang(i, j, n, m);
		}
	}
	
	cout << ans;
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
	
    return 0;
}
