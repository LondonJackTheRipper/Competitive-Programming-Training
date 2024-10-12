#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int MOD = (int) 1e9 + 7;
 
#define ll long long
 
ll pow(ll a, ll b) {
	ll res = 1;
	a %= MOD;
	while (b) {
		if (b % 2 == 1) {
			res *= a;
			res %= MOD;
		}
		b /= 2;
		a *= a;
		a %= MOD;
	}
	return res;
}
 
void input() {
	ll a, b; cin >> a >> b;
	cout << pow(a, b) << '\n';
}
 
int main() {
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	int n; cin >> n;
	while (n--) input();
	return 0;
}
