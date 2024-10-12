#include <iostream>
 
using namespace std;
 
void input() {
	int n; cin >> n;
	int a[n];
	long long s1 = 0, s2 = 1ll * n * (n + 1) / 2;
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
		s1 += 1ll * a[i];
	}
	cout << s2 - s1;
}
 
int main() {
	input();
	return 0;
}
