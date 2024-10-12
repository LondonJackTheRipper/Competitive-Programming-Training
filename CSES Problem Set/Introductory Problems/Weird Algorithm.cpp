#include <iostream>
#include <algorithm>
 
using namespace std;
 
void input() {
	long long n; cin >> n;
	cout << n << " ";
	while (n != 1) {
		if (n % 2 == 0) n /= 2; else n = n * 3 + 1;
		cout << n << " ";
	}
}
 
int main() {
	input();
	return 0;
}
