#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 2e5 + 9;
const ll oo = 1e18 + 9;

void input()
{
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	
	vector<int> dp(n, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		dp[i] = a[i];
		int idx = i + a[i];
		if (idx < n)
			dp[i] += dp[idx];
	}
	
	cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
