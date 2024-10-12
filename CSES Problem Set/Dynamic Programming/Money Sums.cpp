#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 1e6 + 9;
set<int> res;
int dp[maxn];
int n;
 
void add(int num)
{
	for (int i = 100000; i >= num; i--)
	{
		dp[i] += dp[i - num];
		if (dp[i]) res.insert(i);
	}
}
 
void input()
{
	cin >> n;
	
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		add(x);
	}
	
	cout << res.size() << '\n';
	for (auto it : res) cout << it << ' ';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
