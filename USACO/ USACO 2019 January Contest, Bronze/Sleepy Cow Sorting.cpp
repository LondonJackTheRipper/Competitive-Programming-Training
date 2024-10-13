#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

int n;

void input()
{
	cin >> n;
	vector<int> v(n);
	int pos = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i] == 1) pos = i;
	}
	
	vector<bool> dp(n);
	dp[n - 1] = true;
	for (int i = n - 2; i >= 0; i--)
		if (dp[i + 1] && v[i] < v[i + 1]) dp[i] = true;
	
	while (pos < n)
	{
		if (dp[pos])
			break;
		pos++;
	}
	
	cout << pos << '\n';
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}
