#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
 
using namespace std;
 
void input() {
	string s; cin >> s;
	int i = 1, cnt = 1, res = 1;
	while (i != s.length()) {
		if (s[i] == s[i - 1]) {
			cnt++;
			res = max(res, cnt);
			i++;
		} else {
			cnt = 1;
			i++;
		}
	}
	cout << res;
 }
 
int main() {
	input();
	return 0;
}
