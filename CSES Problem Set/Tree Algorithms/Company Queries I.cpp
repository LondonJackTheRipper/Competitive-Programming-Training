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
int par[20][maxn];
int n, q, u, k;
 
int get(int u, int k)
{
	for (int i = 19; i >= 0; i--)
		if ((k >> i) & 1) u = par[i][u];
	if (u == 0) u = -1;
	return u;
}
 
void input()
{
	cin >> n >> q;
	
	par[0][1] = -1;
	for (int i = 2; i <= n; i++) cin >> par[0][i];
	
	for (int i = 1 ; i <= 19; i++)
		for (int j = 1; j <= n; j++)
			par[i][j] = par[i - 1][par[i - 1][j]];
			
	while (q--) cin >> u >> k, cout << get(u, k) << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	input();
	
	return 0;
}
