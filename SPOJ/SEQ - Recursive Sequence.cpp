#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int mod = 1e9;
 
int add(int a, int b) { return ((a % mod) + (b % mod)) % mod; }
int mul(int a, int b) { return (1ll * (a % mod) * (b % mod)) % mod; }
 
class Matrix
{
public:
	vector<vector<int>> data;
	
	int row() { return data.size(); }
	int col() { return data[0].size(); }
	
	Matrix() = default;
	
	Matrix(int r, int c) : data(r, vector<int>(c)) {}
	Matrix(vector<vector<int>> d) : data(d) {}
	
	static Matrix identity(int n)
	{
		Matrix a(n, n);
		while (n--) a.data[n][n] = 1;
		return a;
	}
	
	Matrix operator * (Matrix &b)
	{
		Matrix a = *this;
		Matrix ans(a.row(), b.col());
		
		for (int i = 0; i < a.row(); i++)	
			for (int j = 0; j < b.col(); j++)
				for (int k = 0; k < a.col(); k++)
					ans.data[i][j] = add(ans.data[i][j], mul(a.data[i][k], b.data[k][j]));
					
		return ans;	
	}	
	
	Matrix power(int exp) 
	{
		Matrix base = *this;
		Matrix ans = identity(row());
		
		for (; exp > 0; exp >>= 1, base = base * base)
			if (exp & 1)
				ans = ans * base;
				
		return ans;
	}
};
 
void input()
{
	int k; cin >> k;
	vector<int> b(k), c(k);
	for (int &x : b) cin >> x;
	for (int &x : c) cin >> x; 
	int n; cin >> n;
	
	if (n <= k)
	{
		cout << b[n - 1] << '\n';
		return;
	}
	
	Matrix base(k, 1);
	for (int i = 0; i < k; i++)	base.data[i][0] = b[i];
	Matrix coefficient(k, k);
	for (int i = 0; i < k - 1; i++) coefficient.data[i][i + 1] = 1;
	for (int i = 0; i < k; i++) coefficient.data[k - 1][i] = c[k - i - 1];
	
	Matrix result = coefficient.power(n - k) * base;
	
	cout << result.data[k - 1][0] << '\n';
}
 
signed main()
{
	faster();
 
	int t; cin >> t;
	while (t--) input();
 
	return 0;
}
