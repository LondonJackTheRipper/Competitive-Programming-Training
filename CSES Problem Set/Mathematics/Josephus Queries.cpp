#include <vector>
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
ll solve(ll n, ll k)
{
	if (n == 1)
		return 1;
	if (k <= (n + 1) / 2)
	{
		if (2 * k <= n)
			return 2 * k;
		return (2 * k) % n;
	}
	
	ll tmp = solve(n / 2, k - (n + 1) / 2);
	if (n & 1)
		return 2 * tmp + 1;
	return 2 * tmp - 1;
}
 
void input() 
{
	ll n, k; cin >> n >> k;
	cout << solve(n, k) << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while (q--) input();
	
	return 0;
}
