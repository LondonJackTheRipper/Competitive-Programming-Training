#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

const int maxn = 8009;

int pre[maxn], cnt[maxn];
int n;

void input()
{
	cin >> n;
	
	for (int i = 0; i < maxn; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> pre[i];
		cnt[pre[i]]++;
		pre[i] += pre[i - 1];
	}
	
	int res = 0;
	for (int l = 1; l <= n; l++)
		for (int r = l + 1; r <= n; r++)
		{
			int tmp = pre[r] - pre[l - 1];
			if (tmp >= maxn) continue;
			res += cnt[tmp];
			cnt[tmp] = 0;
		}
		
	cout << res << '\n';
}

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
