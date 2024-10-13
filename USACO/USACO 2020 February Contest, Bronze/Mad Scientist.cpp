#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

int n;

void input()
{
	cin >> n;
	string a, b;
	cin >> a >> b;
	
	int res = 0, i = 0;
	while (i < n)
	{
		if (b[i] != a[i])
		{
			res++;
			while (b[i] != a[i])
				i++;
			i--;
		}
		i++;
	}
	
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

