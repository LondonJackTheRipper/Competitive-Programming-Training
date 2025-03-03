#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;

ll pow1(ll a, ll b)
{
	ll res = 1;
	
	while (b)
	{
		if (b % 2 == 1)
		{
			res *= a;
		}
		
		b /= 2;
		a *= a;
	}
	
	return res;
}

void input()
{
	string s, t; cin >> s >> t;
	int cnt_a = 0;

	for (int i = 0; i < t.length(); i++) if (t[i] == 'a')
	{
		cnt_a++;
	}
	
	if (cnt_a == t.length() && cnt_a == 1) cout << 1 << '\n'; else 
	if (cnt_a >= 1) cout << -1 << '\n'; else 
	cout << pow1(2, s.length()) << '\n';
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	int t; cin >> t;
	while (t--) input();

    return 0;
}

