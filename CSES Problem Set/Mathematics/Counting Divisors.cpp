#include <math.h>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int count_divisors(int x) {
	int res = 0;
	
	for (int i = 1; i <= sqrt(x); i++) {
		if (x % i == 0) {
			res += 2;
		}
		
		if (i * i == x) res--;
	}
	
	return res;
}
 
void input() {
	int x; cin >> x;
	cout << count_divisors(x) << '\n';
}
 
int main() {
	int n; cin >> n;
	while (n--) input();
	return 0;
}
