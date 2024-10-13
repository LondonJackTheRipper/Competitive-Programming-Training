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
	vector<pair<int, int>> vt;
	int mn = 0, mx = 0;
	
	cin >> v[0];
	if (v[0] > 0)
	{
		cout << "-1\n";
		return;
	} else if (v[0] == -1)
		v[0] = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> v[i];
		if (v[i] != -1)
			vt.pb({v[i], i});
	}
	
	for (auto it : vt)
	{
		int x = it.first, pos = it.second; 
		while (v[pos] == x && x > 0)
		{
			pos--; x--;
			if (pos < 0) break;
			if (v[pos] == -1)
				v[pos] = x;
			else if (v[pos] != x)
			{
				cout << "-1\n";
				return;
			} 
		}
	}
	
	for (int x : v)
		if (x == -1)
			mx++; 
		else if (x == 0)
			mx++, mn++;
			
	cout << mn << ' ' << mx << '\n';
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}

