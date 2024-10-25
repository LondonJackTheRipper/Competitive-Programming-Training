#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 3009;
 
int preO[maxn][maxn], preI[maxn][maxn];
char a[maxn][maxn];
int H, W;
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> H >> W;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
		{
			cin >> a[i][j];
			
			preO[i][j] = preO[i][j - 1] + (a[i][j] == 'O');
			preI[i][j] = preI[i - 1][j] + (a[i][j] == 'I');  
		}
 
	ll res = 0;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			if (a[i][j] == 'J')
				res += (preO[i][W] - preO[i][j]) * (preI[H][j] - preI[i][j]);
 
	cout << res << '\n';
 
	return 0;
}
