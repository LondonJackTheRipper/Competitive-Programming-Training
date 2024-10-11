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

int arr[maxn][maxn];
int n;

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++) 
			cin >> arr[i][j];
			
	int cur = arr[1][1];
	for (int i = 2; i <= n; i++)
		cur = (cur >= i ? arr[cur][i] : arr[i][cur]);
	cout << cur << '\n';
	
	return 0;
}
