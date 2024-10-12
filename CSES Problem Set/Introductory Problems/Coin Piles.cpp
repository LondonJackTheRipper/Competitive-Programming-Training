#include <cmath>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
bool check(double a) {
	if (floor(a) == ceil(a)) return true;
	return false;
}
 
void input() {
	long long a, b; cin >> a >> b;
  
	double c1 = (2 * b - a) / (double) 3, c2 = (2 * a - b) / (double) 3;
	if (check(c1) && check(c2) && c1 >= 0 && c2 >= 0) 
    cout << "YES\n"; 
  else 
    cout << "NO\n";
}
 
int main() {
	int t; cin >> t;
	while (t--) input();
	return 0;
}
