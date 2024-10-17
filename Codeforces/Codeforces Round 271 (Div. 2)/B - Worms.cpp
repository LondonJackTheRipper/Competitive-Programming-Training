#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

int main()
{
   faster();

	int n; cin >> n;
	vector<int> pre(n, 0);
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		pre[i] = (i == 0 ? 0 : pre[i - 1]) + x;
	}
	
	int m; cin >> m;
	while (m--)
	{
		int q; cin >> q;
		int pos = lower_bound(pre.begin(), pre.end(), q) - pre.begin();
		
		cout << pos + 1 << '\n';
	}

	return 0;
}
