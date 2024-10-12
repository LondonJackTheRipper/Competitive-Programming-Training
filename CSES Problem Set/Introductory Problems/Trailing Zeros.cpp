#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define ll long long
 
ll solve(ll n) {
	ll res = 0;
	for (ll i = 5; i <= n; i *= 5) {
		res += n / i;
	}
	return res;
}
 
void input() {
	ll n; cin >> n;
	cout << solve(n);
}
 
int main() {
	input();
	return 0;
}
