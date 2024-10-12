#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  Handle codeforces : quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define ll long long
 
const string name = "test";
 
void solve();
signed main()
{
	if (fopen((name + ".inp").c_str(), "r"))
	{
		freopen((name + ".inp").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int t = 1;
//	cin >> t;
	while (t--) solve();
 
	return 0;
}
 
const int maxn = 10;
 
char c[maxn][maxn];
int res = 0;
 
void generate(int rows, vector<int>& cols, vector<int>& diag1, vector<int>& diag2)
{
	if (rows == 8)
	{
		res++;
		return;
	}
	
	for (int i = 0; i < 8; i++)
	{
		if (diag1[rows + i] == 1 || diag2[rows - i + 10] == 1 || cols[i] == 1 || c[rows][i] == '*') continue;
		
		cols[i] = 1;
		diag1[rows + i] = 1;
		diag2[rows - i + 10] = 1;
		generate(rows + 1, cols, diag1, diag2);
		diag1[rows + i] = 0;
		diag2[rows - i + 10] = 0;
		cols[i] = 0;
	}
}
 
void solve()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> c[i][j];
			
	vector<int> cols(8, 0), diag1(30, 0), diag2(30, 0);
	generate(0, cols, diag1, diag2);
	
	cout << res << '\n';
}
