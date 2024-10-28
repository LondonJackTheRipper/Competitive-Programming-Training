#include <iostream>
#include <cmath>

using namespace std;

int a, b, s;

void input() {
	cin >> a >> b >> s;
}

void output() {
	int minvalue = abs(a) + abs(b);
  
	if (s - minvalue >= 0 && (s - minvalue) % 2 == 0) 
		cout << "YES";
	else 
    cout << "NO";
}

int main() {
	input();
	output();
	return 0;
}
