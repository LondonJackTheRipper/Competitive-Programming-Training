#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 2e5 + 9;

int arr[maxn], cp[maxn];
ll pre[maxn];
ll diff[maxn];

int main()
{
   faster();

	int n; cin >> n;
	int q; cin >> q;
	
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1, greater<int>());
	
	while (q--)
	{
		int l, r; cin >> l >> r;
		diff[l]++;
		diff[r + 1]--;
	}
	priority_queue<pair<ll, int>> pq;
	for (int i = 1; i <= n; i++)
	{
		pre[i] = diff[i] + pre[i - 1];
		pq.push({pre[i], i});
	}
	int i = 1;
	while (!pq.empty())
	{
		pair<ll, int> p = pq.top();
		pq.pop();
		
		cp[p.second] = arr[i++];
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) 
		res += 1ll * pre[i] * cp[i];
		
	cout << res << '\n';

	return 0;
}
