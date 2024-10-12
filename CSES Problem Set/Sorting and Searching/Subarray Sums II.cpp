#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back
 
void input()
{
	int n; cin >> n;
	ll x; cin >> x;
	map<ll, int> mp;
	ll res = 0;
	
	ll pre = 0;
	mp[pre]++;
	for (int i = 0; i < n; i++)
	{
		ll a; cin >> a;
		pre += a; 
		res += mp[pre - x];
		mp[pre]++;
	}
	
	cout << res << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
