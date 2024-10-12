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
 
const int maxn = 2e5 + 9;
ll BIT[maxn], a[maxn];
int n, q;
 
ll get(int x)
{
	ll res = 0;
	while (x > 0)
	{
		res += BIT[x];
		x -= (x & (-x));
	}
	
	return res;
}
 
void update(int x, int val)
{
	while (x <= n)
	{
		BIT[x] += val;
		x += (x & (-x));
	}
}
 
void input()
{
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		update(i, a[i]);
	}
	
	while (q--)
	{
		int type, x, y; cin >> type >> x >> y;
		
		if (type == 1)
		{
			update(x, y - a[x]);
			a[x] = y;
		}
		else
		{
			ll ans1 = get(x - 1), ans2 = get(y);
			
			cout << ans2 - ans1 << '\n';
		}
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	input();
	
	return 0;
}
