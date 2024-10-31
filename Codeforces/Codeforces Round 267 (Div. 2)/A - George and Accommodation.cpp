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
	int n; cin >> n;
	int res = 0;
	
	for (int i = 0; i < n; i++)
	{
		int p, q; cin >> p >> q;
		res += (q - p >= 2);
	}
	
	cout << res << '\n';
}

int main()
{
   faster();
   
	input();

	return 0;
}
