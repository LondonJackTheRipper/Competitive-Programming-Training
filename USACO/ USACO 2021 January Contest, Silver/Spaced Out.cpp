#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 1009;
int a[maxn][maxn];
int n;

void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> a[i][j];
		
	int rows = 0, cols = 0;
	for (int i = 0; i < n; i++)
	{
		vector<int> sum(2, 0);
		
		for (int j = 0; j < n; j++)
			sum[j % 2] += a[i][j];
			
		rows += max(sum[0], sum[1]); 
	}
	for (int i = 0; i < n; i++)
	{
		vector<int> sum(2, 0);
		
		for (int j = 0; j < n; j++)
			sum[j % 2] += a[j][i];
			
		cols += max(sum[0], sum[1]);
	}
	
	cout << max(rows, cols) << '\n';
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}

