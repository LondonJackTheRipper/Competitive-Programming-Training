#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

void input()
{
	int n, m; cin >> n >> m;
	vector<int> v(m);
	
	for (int i = 0; i < m; i++) cin >> v[i];
	
	int ans = 0;
	
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < i; j++)
		{
			ans += v[j] < v[i];
		}
	}
	
	cout << ans << '\n';
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	int t; cin >> t;
	while (t--) input();
	
    return 0;
}
