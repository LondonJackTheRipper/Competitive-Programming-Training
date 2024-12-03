#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

vector<int> solve(int n)
{
	vector<int> res;
	int mul = 1;
	
	while (n)
	{
		if (n % 10 != 0)
			res.pb((n % 10) * mul);
		mul *= 10;
		n /= 10;
	}
	
	return res;
}

void input()
{
	int n; cin >> n;
	
	vector<int> ans = solve(n);
	
	cout << ans.size() << '\n';
	for (int x : ans) cout << x << ' ';
	cout << '\n';
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
