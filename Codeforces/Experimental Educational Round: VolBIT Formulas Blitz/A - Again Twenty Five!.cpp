#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 100;

ll pow1(ll a, ll b)
{
	ll res = 1;
	
	while (b)
	{
		if (b % 2 == 1)
		{
			res *= a;
			res %= MOD;
		}
		
		b /= 2;
		a *= a;
		a %= MOD;
	}
	
	return res;
}

void input()
{
	ll n; cin >> n;
	
	cout << pow1(5, n);
}

int main()
{
	input();

    return 0;
}
