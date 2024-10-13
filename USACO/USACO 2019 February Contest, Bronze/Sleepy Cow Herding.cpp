#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

void input()
{
	vector<int> v(3);
	
	for (int &x : v) cin >> x;
	sort(v.begin(), v.end());
	
	int mx = v[1] - v[0], mn = v[2] - v[1];
	if (mx < mn) swap(mx, mn);
	
	if (mx != 1)
	{
		if (mn == 1) mn = (mx == 2 ? 2 : 3); else 
		if (mn == 2) mn = 2; else
			mn = 3;
	}
	
	cout << mn - 1 << '\n' << mx - 1 << '\n';
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}

