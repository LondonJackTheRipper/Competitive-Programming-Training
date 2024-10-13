#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define ll long long
#define pb push_back

const int maxn = 109;

int dx[16] = {-1, 1, 0, 0, 0, 0, -3, 3, -1, -1, 1, 1, -2, -2, 2, 2};
int dy[16] = {0, 0, -1, 1, -3, 3, 0, 0, -2, 2, -2, 2, -1, 1, -1, 1};

int n, t;
int field[maxn][maxn];
vector<vi> dist(maxn, vi(maxn, INT_MAX));
vector<vi> visit(maxn, vi(maxn, 0));

void dijkstra()
{
	priority_queue<vi> pq;
	dist[0][0] = 0;
	pq.push({0, 0, 0});
	
	while (!pq.empty())
	{
		vector<int> tp = pq.top();
		pq.pop();
		int x = tp[1], y = tp[2];
		
		if (visit[x][y]) continue;
		visit[x][y] = 1;
		
		for (int i = 0; i < 16; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
			if (dist[xx][yy] > dist[x][y] + 3 * t + field[xx][yy])
			{
				dist[xx][yy] = dist[x][y] + 3 * t + field[xx][yy];
				pq.push({-dist[xx][yy], xx, yy});
			}
		}
		
		int manhattan = n - 1 - x + n - 1 - y;
		if (manhattan < 3)
			dist[n - 1][n - 1] = min(dist[n - 1][n - 1], dist[x][y] + manhattan * t);
	}
	
	cout << dist[n - 1][n - 1] << '\n';
}

void input()
{
	cin >> n >> t;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> field[i][j];

	dijkstra();
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();
	
	input();

	return 0;
}

