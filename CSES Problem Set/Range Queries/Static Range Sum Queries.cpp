#include<bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
#define ll long long
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define fi first
#define la last
 
int a[200001];
ll pre[200001];
 
void input()
{
	int n, q; cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	
	while (q--)
	{
		int l, r; cin >> l >> r;
		
		cout << pre[r] - pre[l - 1] << '\n';
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
	
    return 0;
}
