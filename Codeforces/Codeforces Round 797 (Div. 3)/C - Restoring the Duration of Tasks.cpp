#include<bits/stdc++.h>

using namespace std;

void input() 
{
	int n; cin >> n;
	vector<pair<int, int>> task(n);
	
	for (int i = 0; i < n; i++) cin >> task[i].first;
	for (int i = 0; i < n; i++) cin >> task[i].second;
	
	vector<int> res;
	res.push_back(task[0].second - task[0].first);
	
	for (int i = 1; i < n; i++) 
	{
		res.push_back(task[i].second - max(task[i].first, task[i - 1].second));
	}
	
	for (int x : res) 
	{
		cout << x << " ";
	}
	cout << '\n';
}

int main() 
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	int t; cin >> t;
	while (t--) input();
	return 0;
}
