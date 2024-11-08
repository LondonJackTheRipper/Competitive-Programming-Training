#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

void input()
{
	int n; cin >> n;
	vector<int> a(n), h(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> h[i];
	int res = 0;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				res += (a[i] == h[j]);
				
	cout << res << '\n';
}

int main()
{
   faster();

	input();

	return 0;
}
