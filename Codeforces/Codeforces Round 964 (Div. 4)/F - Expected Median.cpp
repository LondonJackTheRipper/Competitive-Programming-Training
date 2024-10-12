#include <bits/stdc++.h>
using namespace std;

/*
  John Watson

  Mua Code nhu mua Florentino !!
  
  Tags:
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

const ll mod = 1e9 + 7;
const int maxn = 2e5 + 9;

ll factor[maxn];
int n, k;

ll init(int t)
{
	factor[0] = factor[1] = 1;
	for (int i = 2; i <= t; i++)
		factor[i] = (factor[i - 1] * i) % mod;
}

ll power(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b % 2 == 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	} 
	return res;
}

ll inverse(ll up, ll down)
{
	return (up * power(down, mod - 2)) % mod;
}

ll comb(int k, int n)
{
	if (k > n) return 0;
	ll up = factor[n];
	ll down = (factor[k] * factor[n - k]) % mod;
	return inverse(up, down);
}

void input()
{
	cin >> n >> k;
	
	int num0 = 0, num1 = 0;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (x == 0) num0++; else num1++;
	}
	int tmp = (k + 1) / 2;
	ll res = 0;
	
    	for (int tmp = (k + 1) / 2; tmp <= num1 && tmp <= k; tmp++) 
        	res = (res + comb(tmp, num1) * comb(k - tmp, num0) % mod) % mod;
	
	cout << res << '\n';
}

int main()
{
   	faster();
   
	init(2e5);

	int t; cin >> t;
	while (t--) input();

	return 0;
}
