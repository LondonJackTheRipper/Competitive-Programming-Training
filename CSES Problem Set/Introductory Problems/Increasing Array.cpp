#include <iostream>
#include <algorithm>
 
using namespace std;
 
void input() {
	int n; cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	long long res = 0;
	for (int i = 1; i < n; i++) if (a[i] < a[i - 1]) {
		res += a[i - 1] - a[i];
		a[i] = a[i - 1];
	}
	cout << res;
}
 
int main() {
	input();
	return 0;
}
