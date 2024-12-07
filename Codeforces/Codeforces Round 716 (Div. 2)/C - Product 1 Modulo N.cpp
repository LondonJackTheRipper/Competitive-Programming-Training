#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const int maxn = 1e5 + 9;

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

void input()
{
	int n; cin >> n;
	
	vector<int> prime;
	
	for (int i = 1; i < n; i++) if (GCD(i, n) == 1)
		prime.pb(i);
		
	int length = 0;
	vector<ll> pre(prime.size() + 1);
	pre[0] = 1;
	
	for (int i = 1; i < prime.size(); i++)
		pre[i] = (pre[i - 1] * prime[i]) % n;
	
	for (int i = 0; i < prime.size(); i++)
	{
		if (pre[i] == 1)
			length = i + 1;
	}
	
	cout << length << '\n';
	for (int i = 0; i < length; i++)
		cout << prime[i] << ' ';
}

int main()
{
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
	faster();

	input();

	return 0;
}


