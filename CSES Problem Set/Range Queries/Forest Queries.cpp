#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 1009;
int a[maxn][maxn], pre[maxn][maxn];
int n, q;
 
void input()
{
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			char x; cin >> x;
			if (x == '*') a[i][j] = 1;
		}
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pre[i][j] = a[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
			
	while (q--)
	{
		int x1, x2, y1, y2; 
		cin >> x1 >> y1 >> x2 >> y2;
		
		cout << pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1] << '\n'; 
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
