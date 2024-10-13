#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

void input()
{
	int n, k, b; cin >> n >> k >> b;
	vector<int> sign(n + 1, 0), pre(n + 1, 0);
	
	for (int i = 0; i < b; i++)
	{
		int x; cin >> x;
		sign[x] = 1;
	}
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + sign[i];
	int res = 1e9;
	
	for (int i = 0; i <= n - k; i++)
		res = min(res, pre[i + k] - pre[i]);
		
	cout << res << '\n';
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}

