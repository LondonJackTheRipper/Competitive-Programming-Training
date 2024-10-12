#include <iostream>
#include <math.h>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
void input() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		ll temp1 = 1ll * (i * i) * (i * i - 1) / 2;
		ll temp2 = 4ll * (i - 1) * (i - 2);
		cout << temp1 - temp2 << '\n';
	}
}
 
int main() {
	input();
	return 0;
}
