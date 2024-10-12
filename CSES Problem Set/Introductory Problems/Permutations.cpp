#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
void solve(int n) {
	vector<int> v;
	v.push_back(-2);
	for (int i = 2; i <= n; i += 2) v.push_back(i);
	for (int i = 1; i <= n; i += 2) v.push_back(i);
	if (abs(v[n / 2] - v[n / 2 + 1]) > 1) {
		for (int i = 1; i <= n; i++) cout << v[i] << " ";
	} else cout << "NO SOLUTION";
}
 
void input() {
	int n; cin >> n;
	solve(n);
}
 
int main() {
	input();
	return 0;
}
