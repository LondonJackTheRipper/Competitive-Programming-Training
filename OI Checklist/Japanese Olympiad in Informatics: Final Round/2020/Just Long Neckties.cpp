#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int maxn = 2e5 + 9;
 
int n;
int b[maxn], ans[maxn];
pair<int, int> a[maxn];
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n;
	for (int i = 1; i <= n + 1; i++) cin >> a[i].first, a[i].second = i;
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	sort(a + 1, a + n + 2);
	sort(b + 1, b + n + 1);
	
	multiset<int> se;
	for (int i = 2; i <= n + 1; i++)
		se.insert(max(0, a[i].first - b[i - 1]));
	ans[a[1].second] = *se.rbegin();
	for (int i = 2; i <= n + 1; i++)
	{
		se.insert(max(0, a[i - 1].first - b[i - 1]));
		se.erase(se.find(max(0, a[i].first - b[i - 1])));
		ans[a[i].second] = *se.rbegin();
	}
	
	for (int i = 1; i <= n + 1; i++)
		cout << ans[i] << ' ';
 
	return 0;
}
