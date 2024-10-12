#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <set>
using namespace std;
 
const int MOD = 1e9 + 7;
multiset<int> ticket;
 
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define fi first
#define la last
 
void input()
{
	int n, m, x; cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		ticket.insert(x);
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		auto it = ticket.upper_bound(x);
		
		if (it == ticket.begin()) cout << -1 << '\n'; else
		{
			cout << *(--it) << '\n';
			ticket.erase(it);
		}
	}
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
 
    return 0;
}
