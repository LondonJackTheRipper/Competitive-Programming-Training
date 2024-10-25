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
 
int n;
int arr[maxn];
int ans[maxn];
unordered_map<int, int> rightmost;
 
signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();
 
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		rightmost[arr[i]] = i;
	}
	
	int curpos = 1;
	while (curpos <= n)
	{
		int nxtpos = rightmost[arr[curpos]] + 1;
		for (int i = curpos; i < nxtpos; i++)
			ans[i] = arr[curpos];
		curpos = nxtpos;
	}
	
	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
 
	return 0;
}
