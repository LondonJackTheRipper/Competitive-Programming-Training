#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
int n;
 
void input()
{
	cin >> n;
	vector<int> dp;
	
	while (n--)
	{
		int x; cin >> x;
		int pos = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
		
		if (pos == dp.size())
			dp.pb(x);
		else 
			dp[pos] = x;
	}
	
	cout << dp.size();
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
