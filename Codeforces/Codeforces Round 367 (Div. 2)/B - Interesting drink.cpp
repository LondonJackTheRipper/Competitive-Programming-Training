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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(a.begin(), a.end());
	
	int q; cin >> q;
	while (q--)
	{
		int x; cin >> x;
		int pos = upper_bound(a.begin(), a.end(), x) - a.begin();
		
		cout << pos << '\n';
	}
}

int main()
{
   faster();
   
	input();

	return 0;
}
