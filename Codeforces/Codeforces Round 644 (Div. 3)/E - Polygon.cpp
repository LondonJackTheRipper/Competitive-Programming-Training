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
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			char x; cin >> x;
			a[i][j] = x - '0';
		}
	
	bool res = true;
	for (int i = n - 2; i >= 0; i--)
		for (int j = n - 2; j >= 0; j--)
		{
			if (a[i][j] && !a[i + 1][j] && !a[i][j + 1])
				res = false;
		}
	cout << (res == true ? "YES\n" : "NO\n");
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
