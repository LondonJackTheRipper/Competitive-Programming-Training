#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define vc vector<char>
#define vi vector<int>
#define ll long long
#define pb push_back

int a[51];

void input()
{
	int n; cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int i = 0, j = n - 1;
	int res = 0;
	
	while (i <= j)
	{
		res += a[j] - a[i];
		i++; j--;
	}
	
	cout << res << '\n';
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	int t; cin >> t;
	while (t--) input();
	
	return 0;
}

