#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define vi vector<int>
 
void input() {
	int n; cin >> n;
	vi v(n);
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s.insert(v[i]);
	}
	cout << s.size();
}
 
int main() {
	input();
	return 0;
}
