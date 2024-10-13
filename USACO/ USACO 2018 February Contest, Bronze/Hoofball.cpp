#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

int n;
int a[101], touch[101];

int pass_to(int i)
{
	if (i == 0) return 1;
	if (i == n - 1) return n - 2;
	if (a[i] - a[i - 1] <= a[i + 1] - a[i]) return i - 1;
	return i + 1;
}

void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	for (int i = 0; i < n; i++) touch[pass_to(i)]++;
	
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (touch[i] == 0)
			res++;
		if (touch[i] == 1 && touch[pass_to(i)] == 1 && pass_to(pass_to(i)) == i)
		{
			touch[i] = -999;
			res++;
		}
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

