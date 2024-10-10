#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 2e5 + 9;
int arr[maxn];
int n;

void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	map<tuple<int, int, int>, int> mp;
	ll ans = 0;
	
	for (int i = 0; i < n - 2; i++)
	{
		tuple<int, int, int> triplet = make_tuple(arr[i], arr[i + 1], arr[i + 2]);
		vector<tuple<int, int, int>> mist(3);
		mist[0] = make_tuple(0, arr[i + 1], arr[i + 2]);
		mist[1] = make_tuple(arr[i], 0, arr[i + 2]);
		mist[2] = make_tuple(arr[i], arr[i + 1], 0);
		for (auto strip : mist)
		{
			ans += mp[strip] - mp[triplet];
			mp[strip]++;
		}
		mp[triplet]++;
	}
	
	cout << ans << '\n';	
}

int main()
{
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
