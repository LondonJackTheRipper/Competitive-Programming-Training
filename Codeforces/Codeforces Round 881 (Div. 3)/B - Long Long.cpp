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

int a[200001];

void input()
{
	int n; cin >> n;
	ll s = 0, cnt = 0;
	bool open = false;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += abs(a[i]);
		
		if (a[i] < 0 && !open)
		{
			cnt++;
			open = true;
		} else
		if (a[i] > 0) open = false;
	}
	
	cout << s << " " << cnt << '\n';
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

