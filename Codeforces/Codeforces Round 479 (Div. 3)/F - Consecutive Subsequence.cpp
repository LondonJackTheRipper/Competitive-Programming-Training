#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 2e5 + 9;
vector<int> arr(maxn, 0);
int n;

void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	map<int, int> dp;
	int ans = 0, last = 0;
	for (int i = 0; i < n; i++)
	{
		int x = arr[i];
		dp[x] = dp[x - 1] + 1;
		if (dp[x] > ans)
		{
			ans = dp[x];
			last = x;
		}
	}
	
	cout << ans << '\n'; 
	vector<int> res;
	for (int i = n - 1; i >= 0; i--)
		if (arr[i] == last)
			res.pb(i + 1), last--;
	reverse(res.begin(), res.end());
	
	for (int x : res) cout << x << ' ';
}

int main()
{
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
	faster();

	input();

	return 0;
}


