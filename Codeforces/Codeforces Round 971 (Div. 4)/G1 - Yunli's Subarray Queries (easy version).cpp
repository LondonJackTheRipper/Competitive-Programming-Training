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
const int segsize = 4 * maxn;

unordered_map<int, int> cnt;
int arr[maxn], ans[maxn];
int n, k, q; 

void input()
{
	cin >> n >> k >> q;
	cnt.clear();
	for (int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
		arr[i] -= i;
	}
	
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= k; i++) 
	{
		cnt[arr[i]]++;
		pq.push({cnt[arr[i]], arr[i]});
	}
	ans[1] = k - pq.top().first;
	for (int i = 2; i <= n - k + 1; i++)
	{
		cnt[arr[i - 1]]--;
		cnt[arr[i + k - 1]]++;
		while (!pq.empty() && cnt[pq.top().second] != pq.top().first) pq.pop();
		pq.push({cnt[arr[i - 1]], arr[i - 1]});
		pq.push({cnt[arr[i + k - 1]], arr[i + k - 1]});
		ans[i] = k - pq.top().first;
	}
	
	while (q--)
	{
		int l, r; cin >> l >> r;
		
		cout << ans[l] << '\n';
	}
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
