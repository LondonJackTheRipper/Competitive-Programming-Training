#include <bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back
 
ll power(ll a, ll b, ll mod)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}
 
void input()
{
	ll a, b, c; cin >> a >> b >> c;
	
	cout << power(a, power(b, c, 1e9 + 6), 1e9 + 7) << '\n';
}
 
int main()
{
	faster();
 
	int t; cin >> t;
	while (t--) input();
 
	return 0;
}
