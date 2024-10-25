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

int dx[4] = {0, -1, -1, 0};
int dy[4] = {0, 0, -1, -1};

int mark[maxn][maxn];
char c[maxn][maxn];
string str = "JOI";
char emblem[3][3];
int m, n;
int tmp;

inline bool cancheck(int x, int y) { return 1 <= min(x, y) && x < m && y < n; }

inline int count(int u, int v)
{
	int res = tmp;
	
	for (int i = 0; i < 4; i++)
	{
		int uu = u + dx[i];
		int vv = v + dy[i];
		
		if (!cancheck(uu, vv)) continue;
		if (mark[uu][vv] == 1) 
		{
			res--;
			continue;
		}
		
		if (c[uu][vv] == emblem[1][1] && c[uu + 1][vv] == emblem[2][1] && c[uu][vv + 1] == emblem[1][2] && c[uu + 1][vv + 1] == emblem[2][2])
			res++;
	} 
	
	return res;
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 2; j++)
			cin >> emblem[i][j];
	
	tmp = 0;
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
			int val = (c[i][j] == emblem[1][1] && c[i + 1][j] == emblem[2][1] && c[i][j + 1] == emblem[1][2] && c[i + 1][j + 1] == emblem[2][2]);
			if (val == 1) 
				mark[i][j] = 1;
			tmp += val;	
		}
			
	int ans = tmp;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			char t = c[i][j];

			for (int k = 0; k < 3; k++)
				if (t != str[k])
				{
					c[i][j] = str[k];
					ans = max(ans, count(i, j));
				}
			
			c[i][j] = t;
		}

	cout << ans << '\n';
	
	return 0;
}
