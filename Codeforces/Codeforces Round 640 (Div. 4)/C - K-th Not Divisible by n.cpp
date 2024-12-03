#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

void input()
{
	ll n, k; cin >> n >> k;
	ll t = n - 1;
	ll bracket = (k / t) + (k % t == 0 ? 0 : 1);
	ll r = (k % t == 0 ? t : (k % t));
	
	cout << n * (bracket - 1) + r << '\n';
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
