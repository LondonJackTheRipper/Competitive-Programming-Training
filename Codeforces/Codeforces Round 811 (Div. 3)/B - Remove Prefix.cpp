#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void input()
{
	int n; cin >> n;
	vector<int> v(n);
	map<int, int> mp;
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		mp[v[i]]++;
	}
	
	int res = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (mp[v[i]] > 1) 
		{
			res = i + 1;
			mp[v[i]]--;
		}
	}
	
	cout << res << '\n';
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	int t; cin >> t;
	while (t--) input();
	
	return 0;
}
