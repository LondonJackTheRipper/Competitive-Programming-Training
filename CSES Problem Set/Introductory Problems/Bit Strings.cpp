#include <iostream>
#include <algorithm>
 
using namespace std;
 
const long long MOD = (long long) 1e9 + 7;
 
using ll = long long;
 
ll pow(ll a, ll b) {
	ll res = 1;
	a %= MOD;
	while (b != 0) {
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
	ll n; cin >> n;
	cout << pow(2, n);
}
 
int main() {
	input();
	return 0;
}
