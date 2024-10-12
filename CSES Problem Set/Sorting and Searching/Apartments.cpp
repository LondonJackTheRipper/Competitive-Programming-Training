#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
#define vi vector<int>
 
void input() {
	int n, m, k; cin >> n >> m >> k;
	vi app(n), apart(m);
	for (int i = 0; i < n; i++) cin >> app[i];
	for (int i = 0; i < m; i++) cin >> apart[i];
	
	sort(app.begin(), app.end(), greater<int>());
	sort(apart.begin(), apart.end(), greater<int>());
	
	int i = 0, j = 0, res = 0;
	
	while (i < n && j < m) {
		if (abs(app[i] - apart[j]) <= k) {
			res++; i++; j++;
		} else 
		if (app[i] < apart[j]) {
			j++;
		} else i++;
	}
	
	cout << res;
}
 
int main() {
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
	return 0;
}
