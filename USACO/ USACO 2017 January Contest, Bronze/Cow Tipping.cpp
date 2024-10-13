#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

int arr[11][11];
int n;

pair<int, int> get()
{
	pair<int, int> res = {0, 0};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == 1)
			{
				if (i > res.first)
				{
					res.first = i;
					res.second = j;
				} else if (i == res.first && j > res.second)
					res.second = j;
			}
			
	return res;
}

void input()
{
	cin >> n; 
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
		{
			char x; cin >> x;
			arr[i][j] = x - '0';
		}
			
	int ans = 0;
	while (1)
	{
		pair<int, int> tmp = get();
		if (tmp.first == 0 && tmp.second == 0) break;
		
		for (int i = 1; i <= tmp.first; i++)
			for (int j = 1; j <= tmp.second; j++)
				arr[i][j] ^= 1;
		ans++;
	}
	
	cout << ans << '\n';
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
//	faster();

	input();

	return 0;
}

