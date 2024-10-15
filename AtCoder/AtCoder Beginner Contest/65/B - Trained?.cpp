#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "test";

void solve();
signed main()
{
	if (fopen((name + ".inp").c_str(), "r"))
	{
		freopen((name + ".inp").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
//	cin >> t;
	while (t--) solve();

	return 0;
}

// main program
const int maxn = 1e5 + 9;
const int oo = 1e9;

vector<int> adj[maxn];
int n;

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		int x; cin >> x;
		adj[i].push_back(x);
	}
	
	vector<int> dist(n + 1, oo);
	queue<int> q;
	dist[1] = 0;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		
		for (int v : adj[u])
		{
			if (dist[v] != oo) continue;
			
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	
	cout << (dist[2] == oo ? -1 : dist[2]) << '\n';
}
