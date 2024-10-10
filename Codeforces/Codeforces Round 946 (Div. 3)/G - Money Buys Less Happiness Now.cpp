#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 2e5 + 9;
int c[maxn];
int m, x;

void input()
{
	cin >> m >> x;
	
	for (int i = 0; i < m; i++)	cin >> c[i];
	
	priority_queue<int> pq;
	int budget = 0;
	for (int i = 0; i < m; i++)
	{
		if (budget >= c[i])
		{
			pq.push(c[i]);
			budget -= c[i];
		} else if (!pq.empty() && pq.top() > c[i])
		{
			budget += pq.top() - c[i];
			pq.pop();
			pq.push(c[i]);
		}
		budget += x;
	}
	
	cout << pq.size() << '\n';
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
