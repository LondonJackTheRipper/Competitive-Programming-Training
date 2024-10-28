#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

bool contains(int x, int l, int r)
{
	if (l > r) return false;
	int div1 = (l - 1) / x;
	int div2 = r / x;
	if (l % x == 0 || r % x == 0) return true;
	return (div2 - div1 != 0);
}

void input()
{
	int n; cin >> n;
	
	int res = 1;
	for (int i = 2; i <= n; i++)
		if (contains(i, i + 1, n))
			res = i;
			
	cout << res << '\n';
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
