#include <bits/stdc++.h>
using namespace std;

/*
  John Watson

  Mua Code nhu mua Florentino !!
  
  Tags:
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 100;

int arr[maxn][maxn];
char c[maxn][maxn];
bool check;
int n, m, cnt;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isin(int u, int v)
{
	return (1 <= u && u <= n && 1 <= v && v <= m);
}

void bad(int u, int v)
{
	arr[u][v] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int uu = u + dx[i];
		int vv = v + dy[i];
		
		if (isin(uu, vv))
		{
			if (c[uu][vv] == 'G')	
				check = false;
			else 
				arr[uu][vv] = 1;
		}
	}
}

void travel(int u, int v)
{
	if (c[u][v] == 'G') cnt--;
	arr[u][v] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int uu = u + dx[i];
		int vv = v + dy[i];
		
		if (isin(uu, vv) && arr[uu][vv] == 0)
			travel(uu, vv);
	}
}

void input()
{
	cin >> n >> m;
	check = true;
	cnt = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = 0;
			cin >> c[i][j];
			
			if (c[i][j] == '#')
				arr[i][j] = 1;
			if (c[i][j] == 'G')
				cnt++;
		}
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c[i][j] == 'B')
				bad(i, j);
	if (!check)
	{
		cout << "No\n";
		return;
	}			
	
	if (arr[n][m] == 0) travel(n, m);
			
	cout << (cnt == 0 ? "Yes\n" : "No\n");
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
