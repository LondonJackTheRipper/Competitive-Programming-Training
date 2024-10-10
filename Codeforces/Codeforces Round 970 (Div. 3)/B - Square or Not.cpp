#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 2e5 + 9;
const int mm = 509;

int arr[mm][mm];

inline bool isss(int n)
{
	int sq = sqrt(n);
	return sq * sq == n;
}

void input()
{
	int n; cin >> n;
	int sss = sqrt(n);
	string s; cin >> s;
	if (!isss(n)) { cout << "No\n"; return; }
	
	int cur = 0;
	for (int i = 1; i <= sss; i++)	
		for (int j = 1; j <= sss; j++)
			arr[i][j] = (s[cur++] - '0');
			
	for (int i = 1; i <= sss; i++)
		for (int j = 1; j <= sss; j++)
			if (i == 1 || j == 1 || i == sss || j == sss)
			{
				if (arr[i][j] == 0) { cout << "No\n"; return; }
			} else
				if (arr[i][j] == 1) { cout << "No\n"; return; }
	cout << "Yes\n";
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	int t; cin >> t;
	while (t--) input();
	
	return 0;
}
