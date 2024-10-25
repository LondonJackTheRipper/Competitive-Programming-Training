#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 1e5 + 9;
 
int t[maxn];
int n, k;
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n >> k;
	vector<int> tmp;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		if (i > 1)
			tmp.push_back(t[i] - t[i - 1]);
	}
	sort(tmp.begin(), tmp.end(), greater<int>());
	ll sum = 0;
	for (int i = 0; i < k - 1; i++)
		sum += tmp[i] - 1;
		
	cout << t[n] - t[1] + 1 - sum << '\n';
 
	return 0;
}
