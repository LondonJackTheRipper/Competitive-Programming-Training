#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pll pair<long long, long long>
#define vll vector<long long>
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define vc vector<char>
#define vi vector<int>
#define ll long long
#define pb push_back

int input()
{
	int n; cin >> n;
	int a[200001];
	int ans = ~0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] != i) ans = ans & a[i];
	}
	
	return ans;
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	int t; cin >> t;
	while (t--) cout << input() << '\n';
	
	return 0;
}

