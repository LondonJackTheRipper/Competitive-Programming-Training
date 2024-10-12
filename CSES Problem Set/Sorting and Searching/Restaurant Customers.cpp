#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
#define ll long long
#define pb push_back
#define vs vector<string>
#define pi pair<int, int>
#define vi vector<int>
#define fi first
#define la last
 
void input()
{
	int n, x; cin >> n;
	vector<pi> a;
	
	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> x;
		if (i % 2 == 1) a.push_back({x, 1}); else
			a.push_back({x, -1});
	}
	sort(a.begin(), a.end());
	
	int res = 0, tmp = 0;
	
	for (int i = 0; i < a.size(); i++)
	{
		tmp += a[i].second;
		res = max(res, tmp);
	}
	
	cout << res;
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
	
    return 0;
}
