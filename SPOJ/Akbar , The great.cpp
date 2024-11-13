#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 1e6 + 9;

vector<int> adj[maxn];
int n, r, m;

int protect[maxn];
bool BFS(int s, int k)
{
	if (protect[s] != -1 && protect[s] != s)
		return false;
	
	queue<pair<int, int>> q;
	q.push({s, k});
	protect[s] = s;
	
	while (!q.empty())
	{
		int u = q.front().first;
		int rem = q.front().second;
		q.pop();
		
		if (rem == 0) continue;
		
		for (int v : adj[u])
		{
			if (protect[v] != -1 && protect[v] != s)
				return false;
			
			protect[v] = s;
			q.push({v, rem - 1});
		}
	}
	
	return true;
}

void reset()
{
	for (int i = 1; i <= n; i++)
	{
		adj[i].clear();
		protect[i] = -1;
	}
}

void input()
{
	cin >> n >> r >> m;
	reset();
	
	for (int i = 0; i < r; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	while (m--)
	{
		int s, k;
		cin >> s >> k;
		
		if (!BFS(s, k))
		{
			cout << "No\n";
			return;
		}
	}
	for (int i = 1; i <= n; i++)
		if (protect[i] == -1)
		{
			cout << "No\n";
			return;
		}

	cout << "Yes\n";
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
