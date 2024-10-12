#include <iostream>
#include <algorithm>
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
 
int a[200001];
 
void input()
{
	int n; cin >> n;
	ll s = 1;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= s) s += a[i]; else
			break;
	}
	
	cout << s;
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
	
    return 0;
}
