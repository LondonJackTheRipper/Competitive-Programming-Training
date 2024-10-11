#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int maxn = 500;
const ll oo = 1e18 + 9;

vector<vector<ll>> dist(maxn, vector<ll>(maxn, oo));
vector<tuple<int, int, int>> edges;
int n, m, q;

ll ans = oo;
vector<int> cur;

vector<tuple<int, int, int>> vv;
void update()
{
	int ver = 1;
	ll res = 0;
	for (tuple<int, int, int> id : vv)
	{
		int u = get<0>(id);
		int v = get<1>(id);
		int w = get<2>(id);
		res += dist[ver][u] + w;
		ver = v;
	}

	ans = min(ans, res + dist[ver][n]);
}

void generatemore(int pos)
{
	if (pos == cur.size())
	{
		update();
		return;
	}
	
	int u = get<0>(edges[cur[pos]]);
	int v = get<1>(edges[cur[pos]]);
	int w = get<2>(edges[cur[pos]]);
	vv.push_back(make_tuple(u, v, w));
	generatemore(pos + 1);
	vv.pop_back();
	vv.push_back(make_tuple(v, u, w));
	generatemore(pos + 1);
	vv.pop_back();
}

void generate(int pos, vector<int>& nums, vector<int> mark)
{
	if (pos == nums.size())
	{
		generatemore(0);
		return;
	}
	
	for (int i = 0; i < nums.size(); i++)
		if (mark[i] == 0)
		{
			mark[i] = 1;
			cur.push_back(nums[i]);
			generate(pos + 1, nums, mark);
			cur.pop_back();
			mark[i] = 0;
		}
}

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, t; cin >> u >> v >> t;
		edges.push_back(make_tuple(u, v, t));
		dist[u][v] = dist[v][u] = min(dist[v][u], 1ll * t);
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	// floyd
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	//

	cin >> q;
	while (q--)
	{
		int k; cin >> k;
		vector<int> nums;
		for (int i = 0; i < k; i++)
		{
			int x; cin >> x;
			nums.push_back(x - 1);
		}
		
		ans = oo;
		vector<int> mark(nums.size(), 0);
		generate(0, nums, mark);
		cout << ans << '\n';
	}

	return 0;
}
