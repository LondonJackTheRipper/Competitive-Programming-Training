#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pll pair<long long, long long>
#define vll vector<long long>
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define vc vector<char>
#define vi vector<int>
#define ll long long
#define pb push_back

int a[100001];

void input()
{
	int n; cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	for (int i = 2; i < n; i++)
	{
		if (a[i] < a[i - 1] + a[i - 2])
		{
			cout << "YES\n";
			return;
		}
	}
	
	cout << "NO\n";
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	input();
	
	return 0;
}

