#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

void input()
{
	int a, b; cin >> a >> b;
	int res = abs(a - b);
	
	cout << (res / 10 + (res % 10 == 0 ? 0 : 1)) << '\n';
}

int main()
{
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
