#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 109;
const int oo = 1e9 + 7;

int n;
int a[maxn];
char s[maxn];

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	cin >> n;
	int mnleft = oo, mxleft = -oo;
	int mnright = oo, mxright = -oo;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> s[i];
		if (s[i] == 'L')
		{
			mnleft = min(mnleft, a[i]);
			mxleft = max(mxleft, a[i]);
		} else
		{
			mnright = min(mnright, a[i]);
			mxright = max(mxright, a[i]);
		}
	}
	
	int left = oo, right = oo;
	for (int i = mnleft; i <= mxleft; i++)
	{
		int cur = 0, start = i;
		for (int j = 1; j <= n; j++)
			if (s[j] == 'L')
			{
				cur += abs(a[j] - start);
				start = a[j];
			}
		left = min(left, cur);
	}
	for (int i = mnright; i <= mxright; i++)
	{
		int cur = 0, start = i;
		for (int j = 1; j <= n; j++)
			if (s[j] == 'R')
			{
				cur += abs(a[j] - start);
				start = a[j];
			}
		right = min(right, cur);
	}
		
	cout << (left == oo ? 0 : left) + (right == oo ? 0 : right) << '\n';

	return 0;
}
