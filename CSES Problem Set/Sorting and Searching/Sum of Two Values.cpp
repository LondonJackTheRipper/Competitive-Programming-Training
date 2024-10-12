#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
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
map<int, int> mp;
 
void input()
{
	int n, x; cin >> n >> x;
	int f = -1, s;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		
		if (mp[x - a[i]])
		{
			f = mp[x - a[i]];
			s = i;
			break;
		}
		if (!mp[a[i]]) mp[a[i]] = i;
	}
	
	if (f == -1)
	{
		cout << "IMPOSSIBLE";
	} else cout << f << " " << s;
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
	
    return 0;
}
