#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

vector<int> before[11];
int a[11][11];
int n;

struct art
{
	int mxi = 0, mni = 100, mxj = 0, mnj = 100;
	int cnt = 0;
	bool check = false;
	
	void update(int i, int j)
	{
		cnt++;
		mxi = max(mxi, i);
		mni = min(mni, i);
		mxj = max(mxj, j);
		mnj = min(mnj, j);
	}	
} nodes[11];

void input()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			char x; cin >> x;
			a[i][j] = x - '0';
			nodes[a[i][j]].update(i, j);
		}
		
	for (int k = 1; k <= 9; k++)
		if (nodes[k].cnt)
		{
			int i1 = nodes[k].mni, j1 = nodes[k].mnj, i2 = nodes[k].mxi, j2 = nodes[k].mxj;
			for (int i = i1; i <= i2; i++)
				for (int j = j1; j <= j2; j++)
					if (a[i][j] && a[i][j] != k)
						before[k].pb(a[i][j]);
		}
	for (int i = 1; i <= 9; i++)
		for (int x : before[i]) nodes[x].check = true;
		
	int res = 0;
	for (int i = 1; i <= 9; i++)
		if (nodes[i].cnt && nodes[i].check == false)
			res++;
			
	cout << res << '\n';
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}
