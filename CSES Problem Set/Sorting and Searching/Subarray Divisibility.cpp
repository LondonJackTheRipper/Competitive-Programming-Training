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
	map<int, int> mp;
	mp[0] = 1;
	ll res = 0;
	
	ll pre = 0;
	for (int i = 0; i < n; i++)
	{
		ll x; cin >> x;
		pre += x;
		int div = (pre % n + n) % n;
		res += mp[div];
		mp[div]++;
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
