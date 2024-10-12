#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define fi first
#define la last
 
ll a[200001];
 
void input()
{
	int n; cin >> n;
	ll s1 = 0, s2 = 0;
	ll max_e = INT_MIN;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		max_e = max(max_e, a[i]);
		s2 += a[i];
		s1 = max(s1, s2);
		s2 = max(s2, 1ll * 0);
	}
	
	if (s1 == 0) cout << max_e; else cout << s1;
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
	
    return 0;
}
