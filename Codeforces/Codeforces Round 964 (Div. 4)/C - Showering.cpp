#include <bits/stdc++.h>
using namespace std;

/*
  John Watson

  Mua Code nhu mua Florentino !!
  
  Tags:
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 2e5 + 9;

ll l[maxn], r[maxn];
int n;
ll s, m;

void input()
{
	cin >> n >> s >> m; 
	ll res = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		if (i == 1)
			res = max(res, l[i]);
		if (i == n)
			res = max(res, m - r[i]);
	}
	for (int i = 2; i <= n; i++)
		res = max(res, l[i] - r[i - 1]);
		
	cout << ((res >= s) ? "YES\n" : "NO\n");
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
