#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
#define ll long long
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define fi first
#define la last
 
int a[200001];
 
void input()
{
	int n; cin >> n;
	ll res = 0;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int m = n / 2;
	
	for (int i = m - 1; i >= 0; i--) res += abs(a[m] - a[i]);
	for (int i = m + 1; i < n; i++) res += abs(a[m] - a[i]);
	
	cout << res;
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
	
    return 0;
}
